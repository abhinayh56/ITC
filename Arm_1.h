#ifndef ARM_1_H
#define ARM_1_H

#include "./src/ITC.h"

class Arm_1
{
public:
    Arm_1() {}
    ~Arm_1() {}

    void register_data_elements()
    {
        data_store.register_data_element<int>(element_encoder_count_1);
        data_store.register_data_element<int>(element_encoder_count_2);
        data_store.register_data_element<int>(element_encoder_count_1_other);
        data_store.register_data_element<int>(element_encoder_count_2_other);
    }

    void main_process()
    {
        std::cout << "---" << std::endl;
        data_store.set_data_element<int>(element_encoder_count_1);
        data_store.set_data_element<int>(element_encoder_count_2);
        data_store.set_data_element<int>(element_encoder_count_1_other);
        data_store.set_data_element<int>(element_encoder_count_2_other);

        data_store.get_data_element<int>(element_encoder_count_1);
        data_store.get_data_element<int>(element_encoder_count_2);
        data_store.get_data_element<int>(element_encoder_count_1_other);
        data_store.get_data_element<int>(element_encoder_count_2_other);
    }

private:
    ITC &data_store = ITC::getInstance();
    Data_element<int32_t> element_encoder_count_1 = {"ENC_1", "/path_arm_1", 124};
    Data_element<int32_t> element_encoder_count_2 = {"ENC_2", "/path_arm_1", 180};
    Data_element<int32_t> element_encoder_count_1_other = {"ENC_1", "/path_arm_2", 446};
    Data_element<int32_t> element_encoder_count_2_other = {"ENC_2", "/path_arm_2", 456};
};

#endif // ATM_1_H
