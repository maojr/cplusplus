#include <iostream>

class Vector {
public:
    Vector() {
        std::cout << "constrcutor" << std::endl;
    }
    Vector(const Vector& rhs) {
        std::cout << "copy constrcutor" << std::endl;
    }
    Vector(const Vector&& rhs) {
        std::cout << "move constrcutor" << std::endl;
    }
};

void foo(Vector v) {};

Vector createVector() {
    Vector v;
    return v;
};

int main() {
    Vector v = createVector();
    foo(v);
    foo(std::move(v));
    return 0;
}
