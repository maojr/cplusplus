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
    Base* b = new Derived();
    b->print();

    Derived* d = dynamic_cast<Derived*>(b);
    d->print();

    delete b; // virtual destructor makes it equal 'delete d';

    return 0;
}
