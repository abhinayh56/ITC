#include "Data_store_element.h"

template <typename T>
Data_store_element<T>::Data_store_element(std::string key_, std::string path_, T data_, bool overwrite_)
{
    m_key = key_;
    m_path = path_;
    m_size = sizeof(T);
    m_data = data_;
    
    // data_store.register_element<T>(m_key, m_path, data_, m_size, overwrite_, m_index_data, m_index_mutex);
}

template <typename T>
void Data_store_element<T>::publish()
{
    data_store.register_element<T>(m_key, m_path, m_data, m_size, true, m_index_data, m_index_mutex);
}

template <typename T>
void Data_store_element<T>::subscribe()
{
    data_store.register_element<T>(m_key, m_path, m_data, m_size, false, m_index_data, m_index_mutex);
}

template <typename T>
Data_store_element<T>::~Data_store_element()
{
}

template <typename T>
bool Data_store_element<T>::get(T &data_)
{
    return data_store.get<T>(m_index_data, m_index_mutex, data_, m_size);
}

template <typename T>
bool Data_store_element<T>::set(const T &data_)
{
    return data_store.set<T>(m_index_data, m_index_mutex, data_, m_size);
}

template <typename T>
uint64_t Data_store_element<T>::get_index_data()
{
    return m_index_data;
}

template <typename T>
uint64_t Data_store_element<T>::get_index_mutex()
{
    return m_index_mutex;
}
