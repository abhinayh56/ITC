#include <iostream>
#include "ecClass1.h"
#include "ecClass2.h"

int main()
{
    Class1 c1;
    Class2 c2;

    c1.publish();
    c2.publish();

    c1.subscribe();
    c2.subscribe();

    c1.run();
    c2.run();

    return 0;
}
