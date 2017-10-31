// Q: How do you implement a variadic function in C++?
#include <iostream>

int int_sum(int n, ...) {
    va_list args;
    va_start(args, n);
    int r = 0;
    while(n--) {
        int x = va_arg(args, int);
        r += x;
    }
    va_end(args);
    return r;
}

int main(int argc, char const *argv[])
{
    int num = 5;
    int val = int_sum(num, 1, 2, 3, 4, 5);
    std::cout << val << std::endl;
    return 0;
}