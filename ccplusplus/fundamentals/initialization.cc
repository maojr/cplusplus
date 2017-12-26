#include <stdio.h>
#include <iostream>
// zero initialization: http://en.cppreference.com/w/cpp/language/zero_initialization
// default initialization: http://en.cppreference.com/w/cpp/language/default_initialization
// new A vs new A()
// new A solely causes As default constructor to be called
// new A() is interpreted:
// An object whose initializer is an empty set of parentheses, i.e().
// shall be value-initialized

// POD type
struct C
{
    int x;
    int y;
};

int main()
{
  struct C c0;
  printf("%d : %d\n", c0.x, c0.y);

  static struct C c00; // Zero initialization
  printf("%d : %d\n", c00.x, c00.y);

  struct C c1 = {}; // Zero initialize POD
  printf("%d : %d\n", c1.x, c1.y);

  struct C c01 = {0}; // Zero initialize POD
  printf("%d : %d\n", c01.x, c01.y);

  struct C c11 {}; // Zero initialize POD, in C++11
  printf("%d : %d\n", c11.x, c11.y);

  C c2 = C(); // Zero initialize using default constructor
  std::cout << c2.x << " : " << c2.y << std::endl;

  C c3; // members are random
  std::cout << c3.x << " : " << c3.y << std::endl;

  return 0;
}
