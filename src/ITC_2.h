#ifndef ITC_H_2
#define ITC_H_2

#include <map>
#include <string.h>
#include <vector>
#include <stdint.h>
#include <iostream>
#include <sys/mman.h>

class Data_store
{
public:
    Data_store(const Data_store &) = delete;
    Data_store &operator=(const Data_store &) = delete;

    static Data_store &getInstance()
    {
        static Data_store instance;
        return instance;
    }

    template <typename T>
    uint64_t register_element(std::string key, std::string path, T &value)
    {
        std::string path_key = path + "/" + key;
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
            // m_data_element_map.insert({path_key, m_offset});
            m_data_element_map[path_key] = m_offset;
            std::cout << "INFO: Data element set.         Index: " << m_offset << ", Key: " << key << ", Path: " << path << ", Value: " << value << std::endl;
            m_offset += sizeof(T);
            memcpy(&m_data_buffer[m_offset], &value, sizeof(T));
        }
        else
        {
            m_offset = m_data_element_map[path_key];
            memcpy(&m_data_buffer[m_offset], &value, sizeof(T));
            std::cout << "INFO: Data element already set. Index: " << m_offset << ", Key: " << key << ", Path: " << path << ", Value: " << value << std::endl;
        }

        return m_offset;
    }

    template <typename T>
    void get(uint64_t index, T &value)
    {
        memcpy(&value, &m_data_buffer[index], sizeof(T));
    }

    template <typename T>
    void set(uint64_t index, const T &value)
    {
        memcpy(&m_data_buffer[index], &value, sizeof(T));
    }

private:
    Data_store()
    {
        if (mlockall(MCL_CURRENT | MCL_FUTURE) != 0)
        {
            std::cerr << "WARNING: Failed to lock memory with mlockall\n";
        }

        m_data_buffer.reserve(1024);
    }

    ~Data_store()
    {
    }

    std::vector<uint8_t> m_data_buffer;
    uint64_t m_offset = 0;
    std::map<std::string, uint64_t> m_data_element_map; // key (string name of data element) : value (pointer of data element)
};

template <typename T>
class Data_store_element
{
public:
    Data_store_element(std::string key_, std::string path_, T &value_)
    {
        key = key_;
        path = path_;
        index = data_store.register_element<T>(key, path, value_);
    }

    ~Data_store_element()
    {
    }

    bool get(T &value)
    {
        data_store.get<T>(index, value);
        return true;
    }

    bool set(const T &value)
    {
        data_store.set<T>(index, value);
        return true;
    }

private:
    std::string key;
    std::string path;
    uint64_t index;

    Data_store &data_store = Data_store::getInstance();
};

#endif // ITC_H_2

// using namespace ITC;

// int main()
// {
//     int encoder_count_1 = 105;
//     Data_store_element<int> data_store_element_1("ENCODER_COUNT_1", "/manipulator_1", encoder_count_1);

//     data_store_element_1.get(encoder_count_1);
//     data_store_element_1.set(encoder_count_1);

//     return 0;
// }