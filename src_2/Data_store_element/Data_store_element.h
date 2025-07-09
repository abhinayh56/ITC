#ifndef DATA_STORE_ELEMENT_H
#define DATA_STORE_ELEMENT_H

#include <string>
#include <pthread.h>
#include "../Data_store/Data_store.h"

template <typename T>
struct Data_element
{
    T data;
    pthread_mutex_t m_mutex;
};

template <typename T>
class Data_store_element
{
public:
    Data_store_element(std::string key_, std::string path_, T value_, bool overwrite = true);

    ~Data_store_element();

    bool get(T &value);

    bool set(const T &value);

private:
    std::string m_key;
    std::string m_path;
    uint64_t m_index;

    Data_element<T> data_element;

    Data_store &data_store = Data_store::getInstance();
};

#include "Data_store_element.tpp"

#endif // DATA_STORE_ELEMENT_H
