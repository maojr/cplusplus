// Excerpt from The Annotated STL Sources
#include <iostream>

template <typename T>
class TestCase {
 public:
    static int data1;
    // in-class static constant integer initialization
    static const int data2 = 2;
};

template <typename T>
int TestCase<T>::data1  = 1;

// template specialization
template <>
int TestCase<long>::data1 = 11;

int main()
{
    std::cout << TestCase<char>::data1 << std::endl;
    std::cout << TestCase<int>::data1  << std::endl;
    std::cout << TestCase<long>::data1 << std::endl;

    std::cout << TestCase<char>::data2 << std::endl;
    std::cout << TestCase<int>::data2  << std::endl;
    std::cout << TestCase<long>::data2 << std::endl;
    return 0;
}
