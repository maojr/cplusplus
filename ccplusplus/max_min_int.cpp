// https://www.zhihu.com/question/66949737/answer/248056268
// max_min_int.c 的 C++ 版本
#include <limits>
#include <iostream>

int main()
{
    std::cout << "max int is: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "min int is: " << std::numeric_limits<int>::min() << std::endl;
    return 0;
}