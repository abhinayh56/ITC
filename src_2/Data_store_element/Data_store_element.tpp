#include "Data_store_element.h"

template <typename T>
Data_store_element<T>::Data_store_element(std::string key_, std::string path_, T value_, bool overwrite)
{
    m_key = key_;
    m_path = path_;
    m_index = data_store.register_element<T>(key, path, value_, overwrite);
}

template <typename T>
Data_store_element<T>::~Data_store_element()
{
}

template <typename T>
bool Data_store_element<T>::get(T &value)
{
    data_store.get<T>(m_index, value);
    return true;
}

template <typename T>
bool Data_store_element<T>::set(const T &value)
{
    data_store.set<T>(m_index, value);
    return true;
}
