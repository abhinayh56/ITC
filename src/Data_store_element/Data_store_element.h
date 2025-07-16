#ifndef DATA_STORE_ELEMENT_H
#define DATA_STORE_ELEMENT_H

#include <string>
#include "../Data_store/Data_store.h"

template <typename T>
class Data_store_element
{
public:
    Data_store_element(std::string key_, std::string path_, T data_, bool overwrite_ = true);

    ~Data_store_element();

    bool get(T &data_);

    bool set(const T &data_);

    uint64_t get_index_data();

    uint64_t get_index_mutex();

private:
    std::string m_key;
    std::string m_path;
    T m_data;
    uint64_t m_index_data;
    uint64_t m_index_mutex;
    std::size_t m_size;

    Data_store &data_store = Data_store::getInstance();
};

#include "Data_store_element.tpp"

#endif // DATA_STORE_ELEMENT_H
