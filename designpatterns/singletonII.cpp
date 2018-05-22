// Singleton excerpt from:
// https://developer.android.com/training/articles/smp#more
#include <iostream>
#include <atomic>
#include <mutex>

class Singleton {
public:
    static Singleton* getInstance() {
        Singleton* myInstance = instance.load(std::memory_order_acquire);
        if (myInstance == nullptr) {
            std::lock_guard<std::mutex> lock_guard(mutex);
            myInstance = instance.load(std::memory_order_relaxed);
            if (myInstance == nullptr) {
                myInstance = new Singleton();
                instance.store(myInstance, std::memory_order_release);
            }
        }
        return myInstance;
    }
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;
private:
    Singleton() {};
    static std::atomic<Singleton*> instance;
    static std::mutex mutex;
};
std::atomic<Singleton*> Singleton::instance = nullptr;
std::mutex Singleton::mutex;

class NewSingleton {
public:
    static NewSingleton* getInstance() {
        NewSingleton* myInstance = instance.load(std::memory_order_acquire);
        if (myInstance != nullptr) {
            return myInstance;
        }
        std::lock_guard<std::mutex> lock_guard(mutex);
        if (instance == nullptr)
            instance = new NewSingleton();
        return instance;
    }
    NewSingleton(const NewSingleton&) = delete;
    NewSingleton(NewSingleton&&) = delete;
    NewSingleton& operator=(const NewSingleton&) = delete;
    NewSingleton& operator=(NewSingleton&&) = delete;
private:
    NewSingleton() {};
    static std::atomic<NewSingleton*> instance;
    static std::mutex mutex;
};
std::atomic<NewSingleton*> NewSingleton::instance = nullptr;
std::mutex NewSingleton::mutex;

int main()
{
    NewSingleton::getInstance();
    Singleton::getInstance();
    return 0;
}
