// To pack a class is to place its members directly after each other in memory,
// which can mean that some or all members can be aligned on a boundary smaller
// than the default alignment the target architecture
#include <iostream>

struct S {
    char c;
    short s;
    int i;
    double d;
};

#pragma pack(push, 1)
struct T {
    char c;
    short s;
    int i;
    double d;
};
#pragma pack(pop, 1)

int main()
{
    std::cout << sizeof(int)      << std::endl;
    std::cout << sizeof(char)     << std::endl;
    std::cout << sizeof(short)    << std::endl;
    std::cout << sizeof(double)   << std::endl;
    std::cout << sizeof(struct S) << std::endl;
    std::cout << sizeof(struct T) << std::endl;
    return 0;
}
