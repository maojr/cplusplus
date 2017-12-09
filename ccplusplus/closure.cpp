// implement a function with a state without using a functor
// closure - a function with a state
// stackoverflow link: https://stackoverflow.com/questions/12635184/do-we-have-closures-in-c
#include <iostream>
#include <functional>

std::function<int()> closure_addby(int val, int step) {
    auto f = [val, step]() mutable {
        val = val + step;
        return val;
    };
    return f;
}

int main(int argc, char const *argv[])
{
    auto add2 = closure_addby(11, 2);
    std::cout << add2() << std::endl;
    std::cout << add2() << std::endl;
    return 0;
}