#include "Arm_1.h"
#include "Arm_2.h"

int main()
{
    Arm_1 arm_1;
    Arm_2 arm_2;

    arm_1.register_data_elements();
    arm_2.register_data_elements();

    arm_1.main_process();
    arm_2.main_process();

    return 0;
}
