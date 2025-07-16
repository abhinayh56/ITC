#include <iostream>
#include "./src/Data_store_element.h"

int main()
{
    int32_t data_1 = 0;
    int32_t data_2 = 0;
    int32_t data_3 = 0;
    int32_t data_4 = 0;
    int32_t data_5 = 0;
    int32_t data_6 = 0;
    int32_t data_7 = 0;
    int32_t data_8 = 0;

    Data_store_element<int32_t> dse_1("K_1", "P_1", 125, true);
    Data_store_element<int32_t> dse_2("K_11", "P_1", 127, true);
    Data_store_element<int32_t> dse_3("K_12", "P_1", 127, true);
    Data_store_element<int32_t> dse_4("K_12", "P_1", 45, true);
    Data_store_element<int32_t> dse_5("K_11", "P_1", 446, true);
    Data_store_element<int32_t> dse_6("K_144", "P_1", 446, true);
    Data_store_element<int32_t> dse_7("K_1", "P_1", 446, true);
    Data_store_element<int32_t> dse_8("K_1234", "P_1", 446, true);

    std::cout << "dse_1.index: " << dse_1.get_index_data() << ", dse_1.mutex: " << dse_1.get_index_mutex() << std::endl;
    std::cout << "dse_2.index: " << dse_2.get_index_data() << ", dse_2.mutex: " << dse_2.get_index_mutex() << std::endl;
    std::cout << "dse_3.index: " << dse_3.get_index_data() << ", dse_3.mutex: " << dse_3.get_index_mutex() << std::endl;
    std::cout << "dse_4.index: " << dse_4.get_index_data() << ", dse_4.mutex: " << dse_4.get_index_mutex() << std::endl;
    std::cout << "dse_5.index: " << dse_5.get_index_data() << ", dse_5.mutex: " << dse_5.get_index_mutex() << std::endl;
    std::cout << "dse_6.index: " << dse_6.get_index_data() << ", dse_6.mutex: " << dse_6.get_index_mutex() << std::endl;
    std::cout << "dse_7.index: " << dse_7.get_index_data() << ", dse_7.mutex: " << dse_7.get_index_mutex() << std::endl;
    std::cout << "dse_8.index: " << dse_8.get_index_data() << ", dse_8.mutex: " << dse_8.get_index_mutex() << std::endl;
    return 0;
}
