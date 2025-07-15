#include "Data_store_element.h"

template <typename T>
Data_store_element<T>::Data_store_element(std::string key_, std::string path_, T value_, bool overwrite)
{
    m_key = key_;
    m_path = path_;
    m_data_element.data = value_;
    m_index = data_store.register_element<T>(m_key, m_path, m_data_element, overwrite);
}

template <typename T>
Data_store_element<T>::~Data_store_element()
{
}

template <typename T>
bool Data_store_element<T>::get(T &value)
{
    if (data_store.get<T>(m_index, m_data_element))
    {
        value = m_data_element.data;
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
bool Data_store_element<T>::set(const T &value)
{
    m_data_element.data = value;
    if (data_store.set<T>(m_index, m_data_element))
    {
        return true;
    }
    else
    {
        return false;
    }
}
