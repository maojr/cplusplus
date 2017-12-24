// https://isocpp.org/wiki/faq/strange-inheritance#calling-virtuals-from-ctors
// base class’s constructor calls a virtual function
// In a constructor, the virtual call mechanism is disabled because overriding from derived classes hasn’t yet happened.
// Objects are constructed from the base up, “base before derived”.
#include <iostream>

class A
{
public:
    A() {
        print();
    };
    virtual ~A() {};
    virtual void print() {
        std::cout << "A()" << std::endl;
    }
};

class B : public A
{
public:
    void print() {
        std::cout << "B()" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    B b;
    return 0;
}
