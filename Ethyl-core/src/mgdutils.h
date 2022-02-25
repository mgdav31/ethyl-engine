#pragma once

#include <iostream>
#include <chrono>
#include <thread>

#define LOG(x)	std::cout << x << std::endl;
#define uint	unsigned int
#define ulong   uint64_t

namespace ethyl {
    inline void system_sleep(uint ms)
    {
        LOG("Sleeping for " << ms << "ms");
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
