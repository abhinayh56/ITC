#include "Data_store.h"

Data_store &Data_store::getInstance()
{
    static Data_store instance;
    return instance;
}

template <typename T>
uint64_t Data_store::register_element(std::string key, std::string path, T value, bool overwrite)
{
    std::string path_key = path + "/" + key;
    std::cout << "---\n"
              << path_key << "\n";

    auto it = m_data_element_map.find(path_key);
    uint64_t index = 0;

    Data_element<T> data_element;
    data_element.data = value;

    if (it == m_data_element_map.end())
    {
        size_t alignment = alignof(T);
        uint64_t m_offset_required = (m_offset + alignment - 1) & ~(alignment - 1); // align up

        size_t required_size = m_offset_required + sizeof(T);

        if (required_size > m_data_buffer.size())
        {
            m_data_buffer.resize(required_size);
        }

        index = m_offset_required;
        // m_data_element_map.insert({path_key, index});
        m_data_element_map[path_key] = index;
        std::cout << "INFO: Data element set.         Index: " << index << ", Key: " << key << ", Path: " << path << ", Value: " << value << std::endl;
        m_offset += sizeof(T);
        memcpy(&m_data_buffer[index], &data_element, sizeof(T));
    }
    else
    {
        index = m_data_element_map[path_key];
        if (overwrite)
        {
            memcpy(&m_data_buffer[index], &data_element, sizeof(Data_element<T>));
        }
        else
        {
            memcpy(&data_element, &m_data_buffer[index], sizeof(Data_element<T>));
        }
        std::cout << "INFO: Data element already set. Index: " << index << ", Key: " << key << ", Path: " << path << ", Value: " << value << std::endl;
    }

    return index;
}

template <typename T>
void Data_store::get(uint64_t index, Data_element<T> &data_element)
{
    if (pthread_mutex_trylock(&data_element.mutex) == 0)
    {
        memcpy(&data_element.data, &m_data_buffer[index], sizeof(Data_element<T>));
    }
}

template <typename T>
void Data_store::set(uint64_t index, const Data_element<T> &data_element)
{
    if (pthread_mutex_trylock(&data_element.mutex) == 0)
    {
        memcpy(&m_data_buffer[index], &data_element.data, sizeof(Data_element<T>));
    }
}

Data_store::Data_store()
{
    if (mlockall(MCL_CURRENT | MCL_FUTURE) != 0)
    {
        std::cerr << "WARNING: Failed to lock memory with mlockall\n";
    }

    m_data_buffer.reserve(1024);
}

Data_store::~Data_store()
{
}
