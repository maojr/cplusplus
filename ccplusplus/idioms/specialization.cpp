// explicit (full) template specialization
// Allows customizing the template code for a given set of template arguments
#include <iostream>

template <typename T> // primary template
struct is_void : std::false_type
{
};

template <>
struct is_void<void> : std::true_type
{
};

int main()
{
    std::cout << is_void<char>::value << std::endl;
    std::cout << is_void<void>::value << std::endl;
    return 0;
}
