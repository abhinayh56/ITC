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
    bool register_element(std::string key_, std::string path_, T data_, std::size_t size_, bool overwrite_ = true);

    template <typename T>
    bool get(uint64_t index, T &data_, std::size_t size_);

    template <typename T>
    bool set(uint64_t index, const T &data_, std::size_t size_);

private:
    Data_store();
    ~Data_store();

    std::map<std::string, uint64_t> m_data_element_map;
    std::map<std::string, uint64_t> m_mutex_element_map;
    std::vector<uint8_t> m_data_buffer;
    std::vector<pthread_mutex_t> m_mutex_buffer;
    pthread_mutex_t m_mutex;

    uint64_t m_offset = 0;
};

#include "Data_store.tpp"

#endif // DATA_STORE_H
