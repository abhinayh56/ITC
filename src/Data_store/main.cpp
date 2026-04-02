#include "Data_store.h"
#include <iostream>
#include <stdint.h>
#include <string>

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

    // ds.register_element<uint32_t>("key_1", "path_1", 1293, 4, true, index_data_1, index_mutex_1);
    // ds.register_element<uint32_t>(key_1, path_1, 1293, 4, true, index_data_1, index_mutex_1);
    ds.register_element<uint32_t>(key_1, path_1, value_1, sizeof(value_1), true, index_data_1, index_mutex_1);
    


    return 0;
}
