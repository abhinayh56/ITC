#ifndef ARM_2_H
#define ARM_2_H

#include "ITC.h"

class Arm_2
{
public:
    Arm_2() {}
    ~Arm_2() {}

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

        data_store.get_data<int>(element_encoder_count_1);
        data_store.get_data<int>(element_encoder_count_2);
        data_store.get_data<int>(element_encoder_count_1_other);
        data_store.get_data<int>(element_encoder_count_2_other);
    }

private:
    ITC &data_store = ITC::getInstance();
    Data_element<int32_t> element_encoder_count_1 = {"ENC_1", "/path_arm_2", 45};
    Data_element<int32_t> element_encoder_count_2 = {"ENC_2", "/path_arm_2", 18};
    Data_element<int32_t> element_encoder_count_1_other = {"ENC_1", "/path_arm_1", 88};
    Data_element<int32_t> element_encoder_count_2_other = {"ENC_2", "/path_arm_1", 56};
};

#endif // ATM_2_H
