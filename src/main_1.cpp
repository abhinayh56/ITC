#include <iostream>
#include "./src/Data_store.h"

int main()
{
    Data_store &data_store = Data_store::getInstance();

    bool register_1_data = false;
    bool register_2_data = false;
    bool register_3_data = false;
    bool register_4_data = false;
    uint64_t index_1_data;
    uint64_t index_2_data;
    uint64_t index_3_data;
    uint64_t index_4_data;
    uint64_t index_1_mutex;
    uint64_t index_2_mutex;
    uint64_t index_3_mutex;
    uint64_t index_4_mutex;

    register_1_data = data_store.register_element("K_1", "P_1", 128, sizeof(uint32_t), true, index_1_data, index_1_mutex);
    register_2_data = data_store.register_element("K_11", "P_1", 107, sizeof(uint32_t), true, index_2_data, index_2_mutex);
    register_3_data = data_store.register_element("K_123", "P_1", 549, sizeof(uint32_t), true, index_3_data, index_3_mutex);
    register_4_data = data_store.register_element("K_11", "P_1", 549, sizeof(uint32_t), true, index_4_data, index_4_mutex);

    std::cout << "index_1_data: " << index_1_data << ", index_1_mutex: " << index_1_mutex << std::endl;
    std::cout << "index_2_data: " << index_2_data << ", index_2_mutex: " << index_2_mutex << std::endl;
    std::cout << "index_3_data: " << index_3_data << ", index_3_mutex: " << index_3_mutex << std::endl;
    std::cout << "index_4_data: " << index_4_data << ", index_4_mutex: " << index_4_mutex << std::endl;

    return 0;
}
