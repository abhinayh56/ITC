#include <iostream>
#include <thread>
#include <chrono>
#include "./Data_store_element/Data_store_element.h"

// Simulate a background task updating sensor value
void sensor_task(Data_store_element<float>& sensor)
{
    float value = 0.0f;
    while (true)
    {
        value += 0.1f;
        sensor.set(value);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

// Simulate a task reading sensor value
void consumer_task(Data_store_element<float>& sensor)
{
    float value;
    while (true)
    {
        if (sensor.get(value))
        {
            std::cout << "[Consumer] Sensor value = " << value << std::endl;
        }
        else
        {
            std::cout << "[Consumer] Failed to get sensor value." << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

int main()
{
    std::cout << "Real-Time Data Store Demo" << std::endl;

    // Create/register a float sensor element
    Data_store_element<float> sensor("imu_pitch", "/sensors/imu", 0.0f);

    // Spawn threads
    std::thread sensor_thread(sensor_task, std::ref(sensor));
    std::thread consumer_thread(consumer_task, std::ref(sensor));

    // Let it run for a while
    std::this_thread::sleep_for(std::chrono::seconds(10));

    // Stop threads (in real app, you’d want proper thread shutdown)
    sensor_thread.detach();
    consumer_thread.detach();

    return 0;
}
