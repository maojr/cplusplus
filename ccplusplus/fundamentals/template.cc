#include <iostream>
#include <typeinfo>

template <typename T = float>
class Type
{
 public:
  Type() {
    std::cout << typeid(T).name() << std::endl;
  }
};

int main()
{
  Type<>();
  Type<int>();
  return 0;
}
