#include <assert.h>
#include <memory>
#include <iostream>

class Empty
{
public:
    Empty()  { std::cout << "initilized" << std::endl; };
    Empty(Empty& rhs) {
        std::cout << "copy constructor" << std::endl;
    };
    ~Empty() { std::cout << "destroyed"  << std::endl; };
    void print() {
        std::cout << "Empty class - print()" << std::endl;
    }
};

void func_value(std::shared_ptr<Empty> ptr)
{
    std::cout << "func_value: shared_ptr use_count: " << ptr.use_count() << std::endl;
    ptr->print();
}

// when use shared_ptr as function parameter
// use const shared_ptr reference
void func_reference(const std::shared_ptr<Empty>& ptr)
{
    std::cout << "func_reference: shared_ptr use_count: " << ptr.use_count() << std::endl;
    ptr->print();
}

// passing unique_ptr to function
// use const unique_ptr reference
void unique_func_reference(const std::unique_ptr<Empty>& uptr)
{
    uptr->print();
}

// Move the smart pointer into the function argument
// use std::move
void unique_func(std::unique_ptr<Empty> uptr)
{
    uptr->print();
}

int main(int argc, char const *argv[])
{
    std::cout << "shared_ptr:\n" << std::endl;
    std::shared_ptr<Empty> ptr = std::make_shared<Empty>();
    std::cout << "shared_ptr use_count: " << ptr.use_count() << std::endl;
    func_value(ptr);
    func_reference(ptr);
    ptr.reset(); // delete managed object

    std::cout << "\nunique_ptr:\n" << std::endl;
    std::unique_ptr<Empty> uptr = std::make_unique<Empty>();
    unique_func_reference(uptr);
    unique_func(std::move(uptr));
    assert(uptr == nullptr);

    std::cin.get();
    return 0;
}