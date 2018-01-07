#include <iostream>

class A
{
public:
    int a;
private:
    int b;
protected:
    int c;
};

// Class uses private inheritance
class B : A
{
public:
    void print() {
        std::cout << a << std::endl;
        // std::cout << b << std::endl; // b is not seen in derived class
        std::cout << c << std::endl;
    }
};

class C : public A
{
public:
    void print() {
        std::cout << a << std::endl;
        // std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
};

class D : protected A
{
public:
    void print() {
        std::cout << a << std::endl;
        // std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    // private inheritance
    B b;
    b.print();
    // std::cout << b.a << std::endl;
    // std::cout << b.b << std::endl;
    // std::cout << b.c << std::endl;

    // public inheritance
    C c;
    c.print();
    std::cout << c.a << std::endl;
    // std::cout << c.b << std::endl;
    // std::cout << c.c << std::endl;

    // protected inheritance
    D d;
    d.print();
    // std::cout << d.a << std::endl;
    // std::cout << d.b << std::endl;
    // std::cout << d.c << std::endl;
    return 0;
}