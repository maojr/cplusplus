#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
  std::vector<int> foo(3);
  std::vector<int> bar;
  std::copy(foo.begin(), foo.end(), back_inserter(bar));
  for (auto val : bar)
    std::cout << val << std::endl;
  return 0;
}
