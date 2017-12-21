#include <iostream>

int main(int argc, char const *argv[])
{
  int a = 0b1000000000000001;// a = 0x8001
  std::cout << a << std::endl;
  unsigned char* b = (unsigned char*)&a;
  std::cout << int(*b) << std::endl; // in little endian machine, int(*b) = 1
  std::cout << int(*(b + 1)) << std::endl; // int(*(b+1)) = 128
  return 0;
}
