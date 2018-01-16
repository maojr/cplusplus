// C++ Core Guidelines:
//
// Define and initialize member variables
// in the order of memeber declaration.
#include <iostream>

class Wrinkle
{
public:
    Wrinkle(int i) : a(++i), c(++i), b(++i) {}
    void print() {
        std::cout << "a:" << a << " b:" << b << " c:" << c << std::endl;
    }
private:
    int a;
    int b;
    int c;
};

int main() {
    Wrinkle w(0);
    w.print();
    return 0;
}
