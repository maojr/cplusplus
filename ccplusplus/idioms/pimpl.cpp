#include <iostream>
#include "pimpl.h"

class MyClassImpl
{
public:
    MyClassImpl(MyClass* pBackPtr) : pMainClass(pBackPtr) { }
    ~MyClassImpl() = default;

    void DoSth() { std::cout << "Val (incremented): " << ++val << "\n";}
    void DoConst() const {
        std::cout << "Val: " << val << "\n";
    }

private:
    int val {0};
    MyClass* pMainClass {nullptr}; // back pointer
};


MyClass::MyClass(const MyClass& rhs)
    : pImpl(new MyClassImpl(*rhs.pImpl)) {}

MyClass& MyClass::operator=(const MyClass& rhs) {
    if (this != &rhs)
        pImpl.reset(new MyClassImpl(*rhs.pImpl));
    return *this;
}

void MyClass::DoSth()
{
    pImpl->DoSth();
}

void MyClass::DoConst() const
{
    pImpl->DoConst();
}
