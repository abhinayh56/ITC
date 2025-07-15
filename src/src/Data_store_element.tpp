#include "Data_store_element.h"

template <typename T>
Data_store_element<T>::Data_store_element(std::string key_, std::string path_, T value_, bool overwrite_)
{
    m_key = key_;
    m_path = path_;
    m_data = value_;

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT);
    pthread_mutex_init(m_data_element.mutex, &attr);
    pthread_mutexattr_destroy(&attr);

    m_index = data_store.register_element<T>(m_key, m_path, m_data, overwrite_);
}

template <typename T>
Data_store_element<T>::~Data_store_element()
{
}

template <typename T>
bool Data_store_element<T>::get(T &data_)
{
    if (data_store.get<T>(m_index, m_data_element))
    {
        data_ = m_data_element.data;
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
bool Data_store_element<T>::set(const T &data_)
{
    m_data_element.data = data_;
    if (data_store.set<T>(m_index, m_data_element))
    {
        return true;
    }
    else
    {
        return false;
    }
}
