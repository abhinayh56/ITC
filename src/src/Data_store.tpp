#include "Data_store.h"

Data_store &Data_store::getInstance()
{
    static Data_store instance;
    return instance;
}

template <typename T>
bool Data_store::register_element(std::string key_, std::string path_, T data_, std::size_t size_, bool overwrite_, uint64_t &index_data, uint64_t &index_mutex)
{
    pthread_mutex_lock(&m_mutex);

    std::string path_key = path_ + "/" + key_;
    std::cout << "---\n"
              << path_key << "\n";

    auto it = m_data_element_map.find(path_key);
    uint64_t index_d = 0;
    uint64_t index_m = 0;

    if (it == m_data_element_map.end())
    {
        size_t alignment = alignof(T);
        uint64_t m_offset_required = (m_offset_data + alignment - 1) & ~(alignment - 1); // align up

        size_t required_size = m_offset_required + size_;

        if (required_size > m_data_buffer.size())
        {
            m_data_buffer.resize(required_size);
        }

        index_d = m_offset_required;
        index_m = m_offset_mutex;
        m_data_element_map[path_key].index_data = index_d;
        m_data_element_map[path_key].index_mutex = index_m;

        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT);
        pthread_mutex_init(&m_mutex_buffer[index_m], &attr);
        pthread_mutexattr_destroy(&attr);

        std::cout << "INFO: Data element set.         index_d: " << index_d << ", Key: " << key_ << ", Path: " << path_ << ", Value: " << data_ << std::endl;
        m_offset_data += size_;
        m_offset_mutex += 1;
        memcpy(&m_data_buffer[index_d], &data_, size_);
    }
    else
    {
        index_d = m_data_element_map[path_key].index_data;
        index_m = m_data_element_map[path_key].index_mutex;
        if (overwrite_)
        {
            memcpy(&m_data_buffer[index_d], &data_, size_);
        }
        else
        {
            memcpy(&data_, &m_data_buffer[index_d], size_);
        }
        std::cout << "INFO: Data element already set. index_d: " << index_d << ", Key: " << key_ << ", Path: " << path_ << ", Value: " << data_ << std::endl;
    }

    index_data = index_d;
    index_mutex = index_m;

    pthread_mutex_unlock(&m_mutex);

    return true;
}

template <typename T>
bool Data_store::get(uint64_t index_data, uint64_t index_mutex, T &data_, std::size_t size_)
{
    if (pthread_mutex_trylock(&m_mutex_buffer[index_mutex]) == 0)
    {
        memcpy(&data_, &m_data_buffer[index_data], size_);
        pthread_mutex_unlock(&m_mutex_buffer[index_mutex]);
    }
    return true;
}

template <typename T>
bool Data_store::set(uint64_t index_data, uint64_t index_mutex, const T &data_, std::size_t size_)
{
    if (pthread_mutex_trylock(&m_mutex_buffer[index_mutex]) == 0)
    {
        memcpy(&m_data_buffer[index_data], &data_, size_);
        pthread_mutex_unlock(&m_mutex_buffer[index_mutex]);
    }
    return true;
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
    m_mutex_buffer.reserve(1500);
}

Data_store::~Data_store()
{
    for (auto &m : m_mutex_buffer)
    {
        pthread_mutex_destroy(&m);
    }
    pthread_mutex_destroy(&m_mutex);
}
