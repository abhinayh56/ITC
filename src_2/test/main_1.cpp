#include <iostream>
#include <stdint.h>
#include "../Data_store/Data_store.h"

int main()
{
    Data_element<int8_t> de_11; de_11.data = -1;
    Data_element<int16_t> de_21; de_21.data = -12;
    Data_element<int32_t> de_31; de_31.data = -123;
    Data_element<int64_t> de_41; de_41.data = -1234;
    Data_element<uint8_t> de_12; de_12.data = 1;
    Data_element<uint16_t> de_22; de_22.data = 12;
    Data_element<uint32_t> de_32; de_32.data = 123;
    Data_element<uint64_t> de_42; de_42.data = 1234;

    Data_store &ds = Data_store::getInstance();

    ds.register_element("K_11", "P_11", de_11);
    ds.register_element("K_21", "P_21", de_21);
    ds.register_element("K_31", "P_31", de_31);
    ds.register_element("K_41", "P_41", de_41);
    ds.register_element("K_11", "P_11", de_12);
    ds.register_element("K_21", "P_21", de_22);
    ds.register_element("K_31", "P_31", de_32);
    ds.register_element("K_41", "P_41", de_42);

    return 0;
}
