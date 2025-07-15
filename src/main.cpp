#include <iostream>
#include "./src/Data_store_element.h"

int main()
{
    int16_t data_1 = 111;
    int16_t data_2 = 222;
    Data_store_element<int16_t> de_1("KEY_1", "/path_1", 104, true);
    Data_store_element<int16_t> de_2("KEY_1", "/path_1", 145, true);

    de_1.get(data_1);
    de_2.get(data_2);
    std::cout << "data_1: " << data_1 << std::endl;
    std::cout << "data_2: " << data_2 << std::endl;
    std::cout << "---" << std::endl;

    de_1.set(178);

    de_1.get(data_1);
    de_2.get(data_2);
    std::cout << "data_1: " << data_1 << std::endl;
    std::cout << "data_2: " << data_2 << std::endl;
    std::cout << "---" << std::endl;

    return 0;
}