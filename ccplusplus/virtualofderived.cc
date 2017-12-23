// If a class has a base class with a virtual destructor,
// its destructor (whether user or implicitly declared) is virtual
#include <iostream>

class A
{
public:
    A() {
        std::cout << "A()" << std::endl;
    };
    virtual ~A() {
        std::cout << "~A()" << std::endl;
    };
};

class B : public A
{
public:
    B() {
        std::cout << "B()" << std::endl;
    };
    ~B() {
        std::cout << "~B()" << std::endl;
    };
};

class C : public B
{
public:
    C() {
        std::cout << "C()" << std::endl;
    };
    ~C() {
        std::cout << "~C()" << std::endl;
    };
};

int main(int argc, char const *argv[])
{
    C* c = new C();
    B* b = dynamic_cast<B*>(c); // equals B* b = new C();
    delete b;
    return 0;
}
