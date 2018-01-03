#include <vector>
#include <iostream>

int main()
{
  std::vector<int> v1;
  v1.push_back(1);
  v1.push_back(1);

  std::vector<int> v2;
  v2.push_back(1);
  v2.push_back(1);

  std::vector<int> v3;
  v3.push_back(1);
  v3.push_back(2);

  std::vector<int> v4;
  v4.push_back(1);
  v4.push_back(2);
  v4.push_back(3);

  std::cout << (v1 == v2) << std::endl;
  std::cout << (v2 < v3) << std::endl;
  std::cout << (v3 < v4) << std::endl;
  std::cout << "size: " << v4.size() << " capacity: " << v4.capacity() << std::endl;
  std::cout << "shrink to fit" << std::endl;
  v4.shrink_to_fit();
  std::cout << "size: " << v4.size() << " capacity: " << v4.capacity() << std::endl;
  return 0;
}
