// http://preshing.com/20130930/double-checked-locking-is-fixed-in-cpp11/
// double-checked locking pattern (DCLP) -- notorious case study in lock-free
// programming

#include <atomic>
#include <iostream>
using namespace std;


// Now thread safe
class Singleton
{
public:
    static Singleton* getInstance() {
        Singleton* tmp = instance.load(std::memory_order_relaxed);
        std::atomic_thread_fence(std::memory_order_acquire);
        if (tmp == nullptr) {
            std::lock_guard<std::mutex> lock(mutex);
            tmp = instance.load(std::memory_order_relaxed);
            if (tmp == nullptr) {
                tmp = new Singleton();
                std::atomic_thread_fence(std::memory_order_release);
                instance.store(tmp, std::memory_order_relaxed);
            }
        }
        return tmp;
    };

    static void destroyInstance() {
        Singleton* tmp = instance.load(std::memory_order_acquire);
        if (tmp != nullptr)
            delete tmp;
    }

    void print() {
        std::cout << "Hello, World!" << std::endl;
    }

private:
    Singleton() {};
    Singleton(const Singleton&) {};
    void operator=(const Singleton&) {};

    static std::mutex mutex;
    static std::atomic<Singleton*> instance;
};

std::atomic<Singleton*> Singleton::instance;
std::mutex Singleton::mutex;

int main(int argc, char const *argv[])
{
    Singleton::getInstance()->print();
    Singleton::destroyInstance();
    return 0;
}
