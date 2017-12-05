//
// distinguish between override, overload and overwrite

#include <iostream>

class A
{
public:
    ~A() {
        std::cout << "~A()" << std::endl;
    }

    virtual void print(int a) {
        std::cout << "A::print(int a) - " << a << std::endl;
    }

    // overload:
    // overload happen in the same class
    void print(char c) {
        std::cout << "A::print(char c) - an overload function" << c << std::endl;
    }

    void printX() {
        std::cout << "A::printX()" << std::endl;
    }
};

class B : public A
{
public:
    ~B() {
        std::cout << "~B()" << std::endl;
    }

    // override:
    // only virtual member functions can be marked 'override'
    void print(int b) override {
        std::cout << "B::print(int b) - the overrided function" << b << std::endl;
    }

    // overwrite:
    // overwrite hides the function with the same name from the base class
    // When the derived class's function name is the same with the base class's non-virtual functions's name
    // the base class' functions are hided from the derived class
    void printX() {
        std::cout << "B::printX() - printX() is a overwrite function" << std::endl;
    }

    void printB() {
        std::cout << "B::printB() - printB() can only be called with class B or B*" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << "A* a = new B()" << std::endl;
    A* a = new B();
    a->print(1);
    a->print('a');
    a->printX();
    // a->printB(); you can not call a derived class' method using a base class's pointer
    // even the pointer points to a derived class

    std::cout << "B* b = dynamic_cast<B*>(a)" << std::endl;
    // reinterpret_cast vs dynamic_cast
    B* b = dynamic_cast<B*>(a);
    b->print(1);
    b->printX();
    b->printB();

    std::cout << "deleting..." << std::endl;
    delete b; // use delete b, because the destructor function of A is not virtual

    return 0;
}