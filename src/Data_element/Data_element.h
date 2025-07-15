#ifndef DATA_ELEMENT_H
#define DATA_ELEMENT_H

#include <pthread.h>

template <typename T>
struct Data_element {
    T data;
    pthread_mutex_t mutex;

    Data_element() {
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT);
        pthread_mutex_init(&mutex, &attr);
        pthread_mutexattr_destroy(&attr);
    }

    ~Data_element() {
        pthread_mutex_destroy(&mutex);
    }

    // Delete copy constructor and copy assignment to avoid copying mutex
    Data_element(const Data_element &) = delete;
    Data_element &operator=(const Data_element &) = delete;
};

#endif // DATA_ELEMENT_H
