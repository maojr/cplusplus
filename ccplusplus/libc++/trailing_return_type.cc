#include <iostream>

auto isOdd(int val) -> bool
{
  return val % 2;
}

int main()
{
  std::cout << isOdd(1) << std::endl;
  std::cout << isOdd(2) << std::endl;
  return 0;
}
