#include "Data_store.h"

Data_store &Data_store::getInstance()
{
    static Data_store instance;
    return instance;
}

template <typename T>
uint64_t Data_store::register_element(std::string key_, std::string path_, T data_, std::size_t size_, bool overwrite_)
{
    std::string path_key = path_ + "/" + key_;
    std::cout << "---\n"
              << path_key << "\n";

    auto it = m_data_element_map.find(path_key);
    uint64_t index = 0;

    if (it == m_data_element_map.end())
    {
        size_t alignment = alignof(T);
        uint64_t m_offset_required = (m_offset + alignment - 1) & ~(alignment - 1); // align up

        size_t required_size = m_offset_required + size_;

        if (required_size > m_data_buffer.size())
        {
            m_data_buffer.resize(required_size);
        }

        index = m_offset_required;
        m_data_element_map[path_key] = index;
        std::cout << "INFO: Data element set.         Index: " << index << ", Key: " << key_ << ", Path: " << path_ << ", Value: " << data_ << std::endl;
        m_offset += size_;
        memcpy(&m_data_buffer[index], &data_, size_);
    }
    else
    {
        index = m_data_element_map[path_key];
        if (overwrite_)
        {
            memcpy(&m_data_buffer[index], &data_, size_);
        }
        else
        {
            memcpy(&data_, &m_data_buffer[index], size_);
        }
        std::cout << "INFO: Data element already set. Index: " << index << ", Key: " << key_ << ", Path: " << path_ << ", Value: " << data_ << std::endl;
    }

    return index;
}

template <typename T>
bool Data_store::get(uint64_t index, T &data_, std::size_t size_)
{
    memcpy(&data_, &m_data_buffer[index], size_);
    return true;
}

template <typename T>
bool Data_store::set(uint64_t index, const T &data_, std::size_t size_)
{
    memcpy(&m_data_buffer[index], &data_, size_);
    return true;
}

Data_store::Data_store()
{
    m_data_buffer.reserve(1024);
}

Data_store::~Data_store()
{
}
