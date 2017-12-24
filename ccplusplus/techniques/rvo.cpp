// Return value optimization, simply RVO,
// is a compiler optimization technique that
// allows the compiler to construct the return value of a function at the call site.
#include <iostream>

class Object
{
public:
    Object()
    {
        std::cout << "constructor" << std::endl;
    };
    Object(const Object&)
    {
        std::cout << "copy constructor" << std::endl;
    };
    ~Object(){
        std::cout << "destructor" << std::endl;
    };
};

// what about this? Object& foo()
Object foo()
{
    Object obj;
    return obj;
}

int main(int argc, char const *argv[])
{
    Object obj = foo();
    return 0;
}