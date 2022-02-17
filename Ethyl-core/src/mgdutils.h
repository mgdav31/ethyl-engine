#pragma once

#include <iostream>
#include <chrono>
#include <thread>

#define LOG(x)	std::cout << x << std::endl;
#define uint	unsigned int

inline void system_sleep(uint ms)
{
	LOG("Sleeping for " << ms << "ms");
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
