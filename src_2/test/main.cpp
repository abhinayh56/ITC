#include <iostream>
#include "../ITC.h"

class Manipulator_1
{
public:
    void run()
    {
        Data_store_element<int64_t> encoder_count_1_element("ENCODER_COUNT_1", "MANIPULATOR_1", 45);
        Data_store_element<uint64_t> encoder_count_2_element("ENCODER_COUNT_2", "MANIPULATOR_1", encoder_count_2);
        Data_store_element<int32_t> encoder_count_3_element("ENCODER_COUNT_3", "MANIPULATOR_1", encoder_count_3);
        Data_store_element<uint32_t> encoder_count_4_element("ENCODER_COUNT_4", "MANIPULATOR_1", encoder_count_4);
        Data_store_element<int16_t> encoder_count_5_element("ENCODER_COUNT_5", "MANIPULATOR_1", encoder_count_5);
        Data_store_element<uint16_t> encoder_count_6_element("ENCODER_COUNT_6", "MANIPULATOR_1", encoder_count_6);

        std::cout << "encoder_count_1: " << encoder_count_1 << std::endl;
        std::cout << "encoder_count_2: " << encoder_count_2 << std::endl;
        std::cout << "encoder_count_3: " << encoder_count_3 << std::endl;
        std::cout << "encoder_count_4: " << encoder_count_4 << std::endl;
        std::cout << "encoder_count_5: " << encoder_count_5 << std::endl;
        std::cout << "encoder_count_6: " << encoder_count_6 << std::endl;

        encoder_count_1 = 123456;
        encoder_count_2 = 12345;
        encoder_count_3 = 1234;
        encoder_count_4 = 123;
        encoder_count_5 = 12;
        encoder_count_6 = 1;

        encoder_count_1_element.set(4476);
        encoder_count_2_element.set(encoder_count_2);
        encoder_count_3_element.set(encoder_count_3);
        encoder_count_4_element.set(encoder_count_4);
        encoder_count_5_element.set(encoder_count_5);
        encoder_count_6_element.set(encoder_count_6);

        encoder_count_1_element.get(encoder_count_1);
        encoder_count_2_element.get(encoder_count_2);
        encoder_count_3_element.get(encoder_count_3);
        encoder_count_4_element.get(encoder_count_4);
        encoder_count_5_element.get(encoder_count_5);
        encoder_count_6_element.get(encoder_count_6);

        std::cout << "encoder_count_1: " << encoder_count_1 << std::endl;
        std::cout << "encoder_count_2: " << encoder_count_2 << std::endl;
        std::cout << "encoder_count_3: " << encoder_count_3 << std::endl;
        std::cout << "encoder_count_4: " << encoder_count_4 << std::endl;
        std::cout << "encoder_count_5: " << encoder_count_5 << std::endl;
        std::cout << "encoder_count_6: " << encoder_count_6 << std::endl;
    }

private:
    int64_t encoder_count_1 = 125;
    uint64_t encoder_count_2 = 125;
    int32_t encoder_count_3 = 126;
    uint32_t encoder_count_4 = 127;
    int16_t encoder_count_5 = 128;
    uint16_t encoder_count_6 = 129;
};

class Manipulator_2
{
public:
    void run()
    {
        Data_store_element<int64_t> encoder_count_7_element("ENCODER_COUNT_1", "MANIPULATOR_1", encoder_count_7, true);
        Data_store_element<uint64_t> encoder_count_8_element("ENCODER_COUNT_2", "MANIPULATOR_1", encoder_count_8);
        Data_store_element<int32_t> encoder_count_9_element("ENCODER_COUNT_3", "MANIPULATOR_1", encoder_count_9);
        Data_store_element<uint32_t> encoder_count_10_element("ENCODER_COUNT_4", "MANIPULATOR_1", encoder_count_10);
        Data_store_element<int16_t> encoder_count_11_element("ENCODER_COUNT_5", "MANIPULATOR_1", encoder_count_11);
        Data_store_element<uint16_t> encoder_count_12_element("ENCODER_COUNT_6", "MANIPULATOR_1", encoder_count_12);

        std::cout << "encoder_count_7 : " << encoder_count_7 << std::endl;
        std::cout << "encoder_count_8 : " << encoder_count_8 << std::endl;
        std::cout << "encoder_count_9 : " << encoder_count_9 << std::endl;
        std::cout << "encoder_count_10: " << encoder_count_10 << std::endl;
        std::cout << "encoder_count_11: " << encoder_count_11 << std::endl;
        std::cout << "encoder_count_12: " << encoder_count_12 << std::endl;

        encoder_count_7 = 123456;
        encoder_count_8 = 12345;
        encoder_count_9 = 1234;
        encoder_count_10 = 123;
        encoder_count_11 = 12;
        encoder_count_12 = 1;

        encoder_count_7_element.set(encoder_count_7);
        encoder_count_8_element.set(encoder_count_8);
        encoder_count_9_element.set(encoder_count_9);
        encoder_count_10_element.set(encoder_count_10);
        encoder_count_11_element.set(encoder_count_11);
        encoder_count_12_element.set(encoder_count_12);

        encoder_count_7_element.get(encoder_count_7);
        encoder_count_8_element.get(encoder_count_8);
        encoder_count_9_element.get(encoder_count_9);
        encoder_count_10_element.get(encoder_count_10);
        encoder_count_11_element.get(encoder_count_11);
        encoder_count_12_element.get(encoder_count_12);

        std::cout << "encoder_count_7: " << encoder_count_7 << std::endl;
        std::cout << "encoder_count_8: " << encoder_count_8 << std::endl;
        std::cout << "encoder_count_9: " << encoder_count_9 << std::endl;
        std::cout << "encoder_count_10: " << encoder_count_10 << std::endl;
        std::cout << "encoder_count_11: " << encoder_count_11 << std::endl;
        std::cout << "encoder_count_12: " << encoder_count_12 << std::endl;
    }

private:
    int64_t encoder_count_7 = 105;
    uint64_t encoder_count_8 = 105;
    int32_t encoder_count_9 = 105;
    uint32_t encoder_count_10 = 105;
    int16_t encoder_count_11 = 105;
    uint16_t encoder_count_12 = 105;
};

int main()
{
    Manipulator_1 manipulator_1;
    Manipulator_2 manipulator_2;

    manipulator_1.run();
    std::cout << "|||||\n";
    manipulator_2.run();

    return 0;
}
