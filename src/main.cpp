#include <iostream>
#include "./src/Data_store.h"

int main()
{
    Data_store &data_store = Data_store::getInstance();

    uint64_t index_1 = data_store.register_element<int16_t>("KEY_1", "/path_1", 126, sizeof(int16_t), true);
    int16_t data_1 = 0;
    data_store.get(index_1, data_1, sizeof(int16_t));
    std::cout << "Data_1: " << data_1 << std::endl;

    uint64_t index_2 = data_store.register_element<int16_t>("KEY_1", "/path_1", 120, sizeof(int16_t), true);
    int16_t data_2 = 0;
    data_store.get(index_2, data_2, sizeof(int16_t));
    std::cout << "Data_2: " << data_2 << std::endl;

    data_store.get(index_1, data_1, sizeof(int16_t));
    std::cout << "Data_1: " << data_1 << std::endl;

    data_1 = 446;
    data_store.set(index_1, data_1, sizeof(int16_t));

    data_store.get(index_1, data_1, sizeof(int16_t));
    std::cout << "Data_1: " << data_1 << std::endl;

    data_store.get(index_2, data_2, sizeof(int16_t));
    std::cout << "Data_2: " << data_2 << std::endl;

    data_2 = 78;
    data_store.set(index_2, data_2, sizeof(int16_t));

    data_store.get(index_1, data_1, sizeof(int16_t));
    std::cout << "Data_1: " << data_1 << std::endl;

    data_store.get(index_2, data_2, sizeof(int16_t));
    std::cout << "Data_2: " << data_2 << std::endl;

    return 0;
}