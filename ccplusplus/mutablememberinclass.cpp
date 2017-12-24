// https://stackoverflow.com/questions/32686220/is-it-possible-change-value-of-member-variable-within-const-function
// change the value of member variable within const function
// methods:
// A: declare that member mutable
// B: const_cast to remove constness from the this pointer

// H3C interview:
// If you want to change a member variable's value in a const member function,
// how can you do?

#include <iostream>

class Const
{
public:
    Const(int m = 0, int n = 0) : m(m), n(n) {};
    void print() const {
        const_cast<Const*>(this)->m = 10;
        n = 10;
        std::cout << "m: " << m << std::endl;
        std::cout << "n: " << n << std::endl;
    }
private:
    int m;
    mutable int n;
};

int main(int argc, char const *argv[])
{
    Const cnt;
    cnt.print();
    return 0;
}