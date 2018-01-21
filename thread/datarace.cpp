#include <stdio.h>

#include <mutex>
#include <thread>
#include <iostream>

std::mutex mu;

void function_1() {
    for (int i = 0; i < 100; ++i) {
        // printf("From thread1: %d\n", -i); // thread safe, do not need synchronization
        mu.lock();
        std::cout << "From thread1: " << -i << std::endl; // needs synchronization
        mu.unlock();
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1(function_1);
    for (int i = 0; i < 100; ++i) {
        // printf("From main: %d\n", i);
        mu.lock();
        std::cout << "From main: " << i << std::endl;
        mu.unlock();
    }
    t1.join();
    return 0;
}
