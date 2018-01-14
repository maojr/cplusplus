#include <iostream>

// void printInt(int i) {
//     std::cout << "rvalue & lvalue reference: " << i << std::endl;
// }

void printInt(const int& i) {
    std::cout << "lvalue reference: " << i << std::endl;
}

void printInt(int&& i) {
    std::cout << "rvalue reference: " << i << std::endl;
}

int main() {
    int a = 5;  // a is a lvalue
    printInt(a);
    printInt(6);
    return 0;
}
