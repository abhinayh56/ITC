#ifndef ITC_H
#define ITC_H

#include <iostream>
#include <stdint.h>
#include <map>
#include <cstring>
#include <pthread.h>
#include <vector>

using namespace std;

template <typename T>
struct Data_element
{
    std::string key = "";
    std::string path = "/";
    T value;
    uint64_t index = 0;
};

class ITC
{
public:
    ITC(const ITC &) = delete;
    ITC &operator=(const ITC &) = delete;

    static ITC &getInstance()
    {
        static ITC instance;
        return instance;
    }

    template <typename T>
    void register_data_element(Data_element<T> &data_element)
    {
        pthread_mutex_lock(&m_mutex);

        string path_key = data_element.path + "/" + data_element.key;
        std::cout << "---\n"
                  << path_key << "\n";

        auto it = m_data_element_map.find(path_key);

        if (it == m_data_element_map.end())
        {
            size_t alignment = alignof(T);
            uint64_t m_offset_required = (m_offset + alignment - 1) & ~(alignment - 1); // align up

            size_t required_size = m_offset_required + sizeof(T);


            if (required_size > m_data_buffer.size())
            {
                m_data_buffer.resize(required_size);
            }

            m_offset = m_offset_required;
            data_element.index = m_offset;
            // m_data_element_map.insert({path_key, data_element.index});
            m_data_element_map[path_key] = data_element.index;
            m_offset += sizeof(T);
            memcpy(&m_data_buffer[data_element.index], &data_element.value, sizeof(T));

            std::cout << "INFO: Data element set.         Index: " << data_element.index << ", Key: " << data_element.key << ", Path: " << data_element.path << ", Value: " << data_element.value << std::endl;
        }
        else
        {
            data_element.index = m_data_element_map[path_key];
            memcpy(&m_data_buffer[data_element.index], &data_element.value, sizeof(T));
            std::cout << "INFO: Data element already set. Index: " << data_element.index << ", Key: " << data_element.key << ", Path: " << data_element.path << ", Value: " << data_element.value << std::endl;
        }

        pthread_mutex_unlock(&m_mutex);
    }

    template <typename T>
    void set_data_element(const Data_element<T> &data_element)
    {
        pthread_mutex_lock(&m_mutex);
        memcpy(&m_data_buffer[data_element.index], &data_element.value, sizeof(T));
        pthread_mutex_unlock(&m_mutex);
        std::cout << "W: " << data_element.value << std::endl;
    }

    template <typename T>
    void get_data(Data_element<T> &data_element)
    {
        pthread_mutex_lock(&m_mutex);
        memcpy(&data_element.value, &m_data_buffer[data_element.index], sizeof(T));
        pthread_mutex_unlock(&m_mutex);
        std::cout << "R: " << data_element.value << std::endl;
    }

private:
    ITC()
    {
        pthread_mutex_init(&m_mutex, nullptr);
        m_data_buffer.reserve(1024);
    }

    ~ITC()
    {
        pthread_mutex_destroy(&m_mutex);
    }

    std::vector<uint8_t> m_data_buffer;
    uint64_t m_offset = 0;

    pthread_mutex_t m_mutex;

    map<string, uint64_t> m_data_element_map; // key (string name of data element) : value (pointer of data element)
};

#endif // ITC_H
