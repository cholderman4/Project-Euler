#pragma once

#include <chrono>

template <typename F>
void TimeFunction(F f)
{
    auto start = std::chrono::steady_clock::now();

    const auto result = f();

    auto end = std::chrono::steady_clock::now();

    auto diff = end - start;

    std::cout << "result: " << result << std::endl;

    std::cout << std::chrono::duration<double, std::milli>(diff).count() << " ms" << std::endl;
    //std::cout << std::chrono::duration<double, std::nano>(diff).count() << " ns" << std::endl;
}