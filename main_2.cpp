#include <iostream>
#include "./src/ITC_2.h"

int main()
{
    int64_t encoder_count_1 = 125;
    uint64_t encoder_count_2 = 125;
    int32_t encoder_count_3 = 125;
    uint32_t encoder_count_4 = 125;
    int16_t encoder_count_5 = 125;
    uint16_t encoder_count_6 = 125;

    Data_store_element<int64_t> encoder_count_1_element("ENCODER_COUNT_1", "MANIPULATOR_1", encoder_count_1);
    Data_store_element<uint64_t> encoder_count_2_element("ENCODER_COUNT_2", "MANIPULATOR_1", encoder_count_2);
    Data_store_element<int32_t> encoder_count_3_element("ENCODER_COUNT_3", "MANIPULATOR_1", encoder_count_3);
    Data_store_element<uint32_t> encoder_count_4_element("ENCODER_COUNT_4", "MANIPULATOR_1", encoder_count_4);
    Data_store_element<int16_t> encoder_count_5_element("ENCODER_COUNT_5", "MANIPULATOR_1", encoder_count_5);
    Data_store_element<uint16_t> encoder_count_6_element("ENCODER_COUNT_6", "MANIPULATOR_1", encoder_count_6);

    Data_store_element<int64_t> encoder_count_7_element("ENCODER_COUNT_1", "MANIPULATOR_1", encoder_count_1);
    Data_store_element<uint64_t> encoder_count_8_element("ENCODER_COUNT_2", "MANIPULATOR_1", encoder_count_2);

    return 0;
}
