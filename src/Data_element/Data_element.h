#ifndef DATA_ELEMENT_H
#define DATA_ELEMENT_H

#include <pthread.h>

template <typename T>
struct Data_element
{
    T data;
    pthread_mutex_t *mutex;
};

#endif // DATA_ELEMENT_H