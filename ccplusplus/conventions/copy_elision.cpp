// Omits copy- and move- (since C++11)constructors, resulting in zero-copy pass-by-value semantics.
#include <iostream>

struct C {
    explicit C(int) {}
    // the copy constructor has a visible side effect
    C(const C&) { std::cout << "copy constructor" << std::endl; }
};                     // it modifies an object with static storage duration

int main() {
    // direct-initialization, calls C::C(42)
     C c1(42);
    // copy-initialization elision as direct-initialization
    C c2 = C(42);
    return 0;
}
