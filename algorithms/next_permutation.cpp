// Q: 生成 N 个不同元素全排列
// 这是 next_permutation() 的基本用法，把元素从小到大放好（即字典序最小的排
// 列），然后反复调用 next_permutation()。

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    int elements[] = {1, 2, 3, 4};
    const size_t N = sizeof(elements)/sizeof(elements[0]);
    std::vector<int> vec(elements, elements + N);

    do
    {
        std::copy(vec.begin(), vec.end(),
        std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
    } while (next_permutation(vec.begin(), vec.end()));

    return 0;
 }