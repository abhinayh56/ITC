#include "Data_store.h"
#include <iostream>
#include <stdint.h>
#include <string>

#pragma pack(push, 1)
struct Data_struct
{
    uint8_t a = 1;
    int8_t b = 2;
    uint8_t c = 3;
    // int16_t d = 4;
    // uint32_t e = 5;
    // int32_t f = 6;
};
#pragma pack(pop)

int main()
{
    std::cout << "TEST: Data store" << std::endl;

    Data_store &ds = Data_store::getInstance();
    
    std::string key_1 = "key_1";
    std::string path_1 = "path_1";
    uint32_t value_1 = 1293;
    uint32_t size_1 = 2;
    uint64_t index_data_1;
    uint64_t index_mutex_1;

    ds.register_element<uint32_t>(key_1, path_1, value_1, sizeof(value_1), true, index_data_1, index_mutex_1);
    ds.register_element<uint32_t>("key_11", "path_11", value_1, sizeof(value_1), true, index_data_1, index_mutex_1);
    ds.register_element<uint32_t>("key_11", "path_11", 45, sizeof(value_1), true, index_data_1, index_mutex_1);
    
    // Data_struct struct_1;
    // ds.register_element<Data_struct>("key_12", "path_12", struct_1, sizeof(struct_1), true, index_data_1, index_mutex_1);

    // uint32_t value_1n;
    // uint64_t index_data_1n;
    // uint64_t index_mutex_1n;
    // ds.register_element<uint32_t>("key_1", "path_1", value_1n, sizeof(value_1n), false, index_data_1n, index_mutex_1n);
    // std::cout << index_data_1 << ", " << index_data_1n << ", " << index_mutex_1 << ", " << index_mutex_1n << std::endl;

    // std::cout << value_1n << std::endl;

    // uint32_t value_1nn = 4469;
    // ds.set<uint32_t>(index_data_1, index_mutex_1, value_1nn, sizeof(value_1n));
    // ds.get<uint32_t>(index_data_1, index_mutex_1, value_1n, sizeof(value_1n));

    // std::cout << value_1n << std::endl;

    return 0;
}
