#pragma once

#include <iostream>
#include <chrono>
#include <thread>

#define LOG(x)	std::cout << x << std::endl;
#define TIME_NOW		std::chrono::high_resolution_clock::now()
#define GET_TIME(x, y)	std::chrono::duration_cast<std::chrono::y>(x).count()
#define uint	unsigned int


namespace ethyl {
    inline void system_sleep(uint ms)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    inline void clearArray(float elements[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            elements[i] = 0.0f;
        }
    }
}
