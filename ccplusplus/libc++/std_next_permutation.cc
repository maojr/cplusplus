#include <vector>
#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::vector<int> v = {1, 3, 2};
    std::sort(v.begin(), v.end());

    do
        std::cout << v[0] << " -> " << v[1] << " -> " << v[2] << std::endl;
    while (std::next_permutation(v.begin(), v.end()));

    return 0;
}
