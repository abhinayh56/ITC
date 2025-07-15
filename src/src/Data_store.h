#ifndef DATA_STORE_H
#define DATA_STORE_H

#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <stdint.h>
#include <iostream>
#include <pthread.h>
#include <sys/mman.h>

class Data_store
{
public:
    Data_store(const Data_store &) = delete;
    Data_store &operator=(const Data_store &) = delete;
    static Data_store &getInstance();

    template <typename T>
    uint64_t register_element(std::string key, std::string path, Data_element<T> &data_element, bool overwrite = true);

    template <typename T>
    bool get(uint64_t index, Data_element<T> &data_element);

    template <typename T>
    bool set(uint64_t index, Data_element<T> &data_element);

private:
    Data_store();
    ~Data_store();

    std::map<std::string, uint64_t> m_data_element_map; // key (string name of data element) : value (pointer of data element)
    std::vector<uint8_t> m_data_buffer;
    uint64_t m_offset = 0;
    pthread_mutex_t m_mutex;
};

#include "Data_store.tpp"

#endif // DATA_STORE_H
