#include <iostream>

// int lg(int n), return binary logarithm result of n
// >> is better than /
int lg(int n) {
    int result = 0;
    for (; n != 1; n >>= 1)
        ++result;
    return result;
}

int main() {
    std::cout << (lg(1) == 0) << std::endl;
    std::cout << (lg(2) == 1) << std::endl;
    std::cout << (lg(3) == 1) << std::endl;
    std::cout << (lg(4) == 2) << std::endl;
    std::cout << (lg(5) == 2) << std::endl;
    std::cout << (lg(6) == 2) << std::endl;
    return 0;
}
