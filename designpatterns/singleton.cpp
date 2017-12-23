#include <iostream>
using namespace std;

// Not thread safe
class Singleton
{
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
            std::cout << "init instance" << std::endl;
        }
        return instance;
    }

    static void destroyInstance() {
        if (instance) {
            delete instance;
            instance = nullptr;
            std::cout << "destroy instance" << std::endl;
        }
    }

    void print() {
        std::cout << "Hello, World!" << std::endl;
    }

private:
    Singleton() {};
    Singleton(const Singleton&) {};
    void operator=(const Singleton&) {};
    static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;

// thread safe in C++ 11
class NewSingleton
{
public:
    static NewSingleton& getInstance() {
        static NewSingleton instance;
        return instance;
    }
    NewSingleton(const NewSingleton&) = delete;
    void operator=(const NewSingleton&) = delete;
    void print() { std::cout << "NewSingleton" << std::endl; };
private:
    NewSingleton() {};
};


int main(int argc, char const *argv[])
{
    Singleton::getInstance()->print();
    Singleton::destroyInstance();

    NewSingleton::getInstance().print();
    return 0;
}
