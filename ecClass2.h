#pragma once

#include "./src/Data_store_element/Data_store_element.h"

class Class2
{
public:
    Class2() :
    a2e1("encoder_1", "arm_2", -567, true),
    a2e2("encoder_2", "arm_2", 894, true),

    a1e1("encoder_1", "arm_1", 0, false),
    a1e2("encoder_2", "arm_1", 0, false)
    {
    }

    ~Class2()
    {
    }

    void publish()
    {
        a2e1.publish();
        a2e2.publish();
    }

    void subscribe()
    {
        a1e1.subscribe();
        a1e2.subscribe();
    }

    void run()
    {
        std::cout << "class2\n";

        uint32_t a1e1_val;
        int32_t a1e2_val;

        a1e1.get(a1e1_val);
        a1e2.get(a1e2_val);

        std::cout << a1e1_val << "\n";
        std::cout << a1e2_val << "\n";
    }

private:
    Data_store_element<int32_t>  a2e1;
    Data_store_element<uint32_t> a2e2;

    Data_store_element<uint32_t> a1e1;
    Data_store_element<int32_t>  a1e2;
};
