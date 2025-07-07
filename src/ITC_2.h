#ifndef ITC_H_2
#define ITC_H_2

#include <map>
#include <string>
#include <vector>
#include <stdint.h>
#include <sys/mman.h>

template <typename T>
class Data_store_element
{
public:
    Data_store_element(std::string key_, std::string path_, T &value_)
    {
        key = key_;
        path = path_;
        index = data_store.register_element(key, path, value_);
    }

    ~Data_store_element()
    {
    }

    bool get(T &value)
    {
        data_store.get(index, value);
    }

    bool set(const T &value)
    {
        data_store.set(index, value);
    }

private:
    std::string key;
    std::string path;
    uint64_t index;

    Data_store &data_store = Data_store::getInstance();
};

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
    uint64_t register_element(std::string key_, std::string path_, T &value_)
    {
        return 0;
    }

    template <typename T>
    void get(uint64_t index, T &value)
    {
        memcpy(value, &m_data_buffer[index], sizeof(T));
    }

    template <typename T>
    void set(uint64_t index, const T &value_)
    {
        memcpy(&m_data_buffer[index], value, sizeof(T));
    }

private:
    Data_store()
    {
        if (mlockall(MCL_CURRENT | MCL_FUTURE) != 0)
        {
            std::cerr << "WARNING: Failed to lock memory with mlockall\n";
        }
    }

    ~Data_store()
    {
    }

    std::vector<uint8_t> m_data_buffer;
    uint64_t m_offset = 0;
    std::map<std::string, uint64_t> m_data_element_map; // key (string name of data element) : value (pointer of data element)
    m_data_buffer.reserve(1024);
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