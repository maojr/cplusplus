#include <iostream>

class Base { 
    public:
    virtual ~Base() { std::cout << "~Base\n"; }
    void print() { std::cout << "Base" << std::endl; }
};

class Derived: public Base {
public:
    ~Derived() { std::cout << "~Derived\n"; }
    void print() { std::cout << "Derived" << std::endl; }
};

int main() {
    Base* b = new Derived();
    b->print();

    Derived* d = dynamic_cast<Derived*>(b);
    d->print();

    delete b;

    return 0;
}