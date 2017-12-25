#include <mutex>
#include <iostream>

int val = 0;
std::mutex val_mutex;

void func() {
    val_mutex.lock();
    std::cout << val << std::endl;
    val_mutex.unlock();
}

int recursive_val = 0;
std::recursive_mutex recursive_val_mutex;

void recursive_func() {
    recursive_val_mutex.lock();
    std::cout << recursive_val++ << std::endl;
    if (recursive_val == 1)
        recursive_func();
    recursive_val_mutex.unlock();
}

int main(int argc, char const *argv[])
{
    func();
    recursive_func();
    return 0;
}
