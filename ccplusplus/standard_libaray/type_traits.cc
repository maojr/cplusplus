#include <iostream>
#include <type_traits>

void test() {}

int main() {
  std::cout << std::is_object<int>::value << std::endl;
  std::cout << std::is_pointer<int*>::value << std::endl;
  std::cout << std::is_reference<int&>::value << std::endl;
  std::cout << std::is_function<decltype(test)>::value << std::endl;
  return 0;
}
