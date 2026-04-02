#pragma once

#include "./src/Data_store_element/Data_store_element.h"

class Class1
{
public:
    Class1() :
    a1e1("encoder_1", "arm_1", 123, true),
    a1e2("encoder_2", "arm_1", -324, true),

    a2e1("encoder_1", "arm_2", 0, false),
    a2e2("encoder_2", "arm_2", 0, false)
    {
    }

    ~Class1()
    {
    }

    void publish()
    {
        a1e1.publish();
        a1e2.publish();
    }

    void subscribe()
    {
        a2e1.subscribe();
        a2e2.subscribe();
    }

    void run()
    {
        std::cout << "class1\n";

        int32_t a2e1_val;
        uint32_t a2e2_val;

        a2e1.get(a2e1_val);
        a2e2.get(a2e2_val);

        std::cout << a2e1_val << "\n";
        std::cout << a2e2_val << "\n";
    }

private:
    Data_store_element<uint32_t> a1e1;
    Data_store_element<int32_t>  a1e2;

    Data_store_element<int32_t>  a2e1;
    Data_store_element<uint32_t> a2e2;
};
