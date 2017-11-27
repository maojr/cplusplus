
// From MSDN,
// A virtual function is a member function that you expect to be redefined in derived classes.
// When you refer to a derived class object using a pointer or a reference to the base class,
// you can call a virtual function for that object and execute the derived class's version of the function.
//
// virtual functions can be used with references.

#include <iostream>

class Base {
    public:
    virtual ~Base() { std::cout << "~Base\n"; }
    void print() { std::cout << "base print" << std::endl; }
};

class Derived: public Base {
public:
    ~Derived() { std::cout << "~Derived\n"; }
    void print() { std::cout << "derived print" << std::endl; }
};

int main() {
    Derived a;

    Base& b = a;
    b.print();

    // dynamic_cast is used to cast a reference or pointer
    Derived& d = dynamic_cast<Derived&>(b);
    d.print();

    return 0;
}
