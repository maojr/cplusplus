// std::bind
// example: pointer to class member is callable object

#include <functional>
#include <iostream>

using namespace std::placeholders;

struct Foo {
  int data = 10;
};

int main() {
  auto f4 = std::bind(&Foo::data, _1);
  Foo foo;
  std::cout << f4(foo) << '\n';
  return 0;
}
