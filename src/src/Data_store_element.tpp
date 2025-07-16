#include "Data_store_element.h"

template <typename T>
Data_store_element<T>::Data_store_element(std::string key_, std::string path_, T data_, bool overwrite_)
{
    m_key = key_;
    m_path = path_;
    m_data = data_;
    m_size = sizeof(T);

    data_store.register_element<T>(m_key, m_path, m_data, m_size, overwrite_, &m_index_data, &m_index_mutex);
}

template <typename T>
Data_store_element<T>::~Data_store_element()
{
}

template <typename T>
bool Data_store_element<T>::get(T &data_)
{
    bool flag = data_store.get<T>(m_index_data, m_index_mutex, m_data, m_size);
    data_ = m_data;
    return flag;
}

template <typename T>
bool Data_store_element<T>::set(const T &data_)
{
    m_data = data_;
    bool flag = data_store.set<T>(m_index_data, m_index_mutex, m_data, m_size);
    return flag;
}
