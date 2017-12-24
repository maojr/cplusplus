#include <vector>
#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::vector<int> v = {1, 3, 5, 7, 9};

    auto iter = std::find(v.begin(), v.end(), 3);
    std::cout << *iter << std::endl;

    iter = std::find(v.begin(), v.end(), 10);
    std::cout << *iter << std::endl; // not found, *iter = -1

    // use of std::begin & std::end
    iter = std::find(std::begin(v), std::end(v), 11);
    std::cout << (iter == v.end()) << std::endl;
    std::cout << (iter == std::end(v)) << std::endl;

    // std::find - the index
    iter = std::find(std::begin(v), std::end(v), 5);
    if (iter != std::end(v))
        std::cout << "Value found! index = " << iter - std::begin(v) << std::endl;

    return 0;
}
