// Solve topk problem with C++ standard library
// std::nth_element is faster than std::partial_sort

#include <time.h>
#include <stdlib.h>

#include <vector>
#include <iostream>
#include <algorithm>

const int N = 1000000;

int main()
{
    std::vector<int> v1(N);
    std::srand(0);
    std::generate(v1.begin(), v1.end(), std::rand);
    std::vector<int> v2 = v1;

    clock_t begin = clock();
    std::nth_element(v1.begin(), v1.begin() + N/2, v1.end(), std::greater<int>());
    std::cout << "std::nth_element:  " << double(clock() - begin) / CLOCKS_PER_SEC << " secs" << std::endl;

    begin = clock();
    std::partial_sort(v2.begin(), v2.begin() + N/2, v2.end(), std::greater<int>());
    std::cout << "std::partial_sort: "<< double(clock() - begin) / CLOCKS_PER_SEC << " secs" << std::endl;
    return 0;
}
