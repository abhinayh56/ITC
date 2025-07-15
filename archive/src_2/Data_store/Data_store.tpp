#include "Data_store.h"

Data_store &Data_store::getInstance()
{
    static Data_store instance;
    return instance;
}

template <typename T>
uint64_t Data_store::register_element(std::string key, std::string path, Data_element<T> &data_element, bool overwrite)
{
    pthread_mutex_lock(&m_mutex);

    std::string path_key = path + "/" + key;
    std::cout << "---\n"
              << path_key << "\n";

    auto it = m_data_element_map.find(path_key);
    uint64_t index = 0;

    if (it == m_data_element_map.end())
    {
        size_t alignment = alignof(T);
        uint64_t m_offset_required = (m_offset + alignment - 1) & ~(alignment - 1); // align up

        size_t required_size = m_offset_required + sizeof(Data_element<T>);

        if (required_size > m_data_buffer.size())
        {
            m_data_buffer.resize(required_size);
        }

        index = m_offset_required;
        m_data_element_map[path_key] = index;
        std::cout << "INFO: Data element set.         Index: " << index << ", Key: " << key << ", Path: " << path << ", Value: " << data_element.data << std::endl;
        m_offset += sizeof(T);
        memcpy(&m_data_buffer[index], &data_element, sizeof(Data_element<T>));
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
        std::cout << "INFO: Data element already set. Index: " << index << ", Key: " << key << ", Path: " << path << ", Value: " << data_element.data << std::endl;
    }
    pthread_mutex_unlock(&m_mutex);

    return index;
}

template <typename T>
bool Data_store::get(uint64_t index, Data_element<T> &data_element)
{
    if (pthread_mutex_trylock(&data_element.mutex) == 0)
    {
        memcpy(&data_element.data, &m_data_buffer[index], sizeof(T));
        pthread_mutex_unlock(&data_element.mutex);
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
bool Data_store::set(uint64_t index, Data_element<T> &data_element)
{
    if (pthread_mutex_trylock(&data_element.mutex) == 0)
    {
        memcpy(&m_data_buffer[index], &data_element.data, sizeof(T));
        pthread_mutex_unlock(&data_element.mutex);
        return true;
    }
    else
    {
        return false;
    }
}

Data_store::Data_store()
{
    if (mlockall(MCL_CURRENT | MCL_FUTURE) != 0)
    {
        std::cerr << "WARNING: Failed to lock memory with mlockall\n";
    }

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT);
    pthread_mutex_init(&m_mutex, &attr);
    pthread_mutexattr_destroy(&attr);

    m_data_buffer.reserve(1024);
}

Data_store::~Data_store()
{
}
