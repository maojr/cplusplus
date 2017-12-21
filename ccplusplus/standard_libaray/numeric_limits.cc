#include <limits>
#include <iostream>

int main()
{
  std::cout << std::numeric_limits<int>::digits << std::endl;
  std::cout << std::numeric_limits<int>::min()  << std::endl;
  std::cout << std::numeric_limits<int>::max()  << std::endl;

  std::cout << std::numeric_limits<unsigned int>::digits << std::endl;
  std::cout << std::numeric_limits<unsigned int>::min() << std::endl;
  std::cout << std::numeric_limits<unsigned int>::max() << std::endl;

  std::cout << std::numeric_limits<char>::digits << std::endl;
  std::cout << static_cast<int>(std::numeric_limits<char>::min()) << std::endl;
  std::cout << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;

  std::cout << std::numeric_limits<float>::digits << std::endl;
  std::cout << std::numeric_limits<float>::min() << std::endl;
  std::cout << std::numeric_limits<float>::max() << std::endl;

  return 0;
}
