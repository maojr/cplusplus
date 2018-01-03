// std=c++11
#include <iostream>

template<typename T>
struct is_void : std::false_type
{
};

// specializations
template<>
struct is_void<void> : std::true_type
{
};

int main()
{
  std::cout << is_void<char>::value << std::endl;
  std::cout << is_void<void>::value << std::endl;
  return 0;
}
