// ::(scope resolution) operator is used to qualify hidden names so that you can still use them.
// You can use the unary scope operator if a namespace scope or global scope name is hidden by an explicit declaration of the same name in a block or class. 

#include <iostream>

int count = 0;

class X
{
public:
    static int count;
};

int X::count = 10;

int main(int argc, char const *argv[])
{
    int count = 0;
    ::count = 1;

    std::cout << "cout     == " << count    << std::endl;
    std::cout << "::cout   == " << ::count  << std::endl;
    std::cout << "X::count == " << X::count << std::endl;

    return 0;
}