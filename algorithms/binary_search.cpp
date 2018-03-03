#include <iostream>
#include <algorithm>

int binary_search(int* a, int length, int val) {
  int start = 0;
  int mid = 0;
  int end = length - 1;
  while (start <= end) {
    mid = (start + end) / 2;
    if (a[mid] == val)
      return mid;
    else if (a[mid] < val)
      start = mid + 1;
    else
      end = mid - 1;
  }
  return -1;
}

// the recursive version
// interview at http://aqrose.com/
int recursive_binary_search(int* arr, int start, int end, int val) {
  if (start > end) return -1;

  int mid = start + (end - start) / 2;
  if (arr[mid] == val)
    return mid;
  else if (arr[mid] > val)
    return recursive_binary_search(arr, start, mid - 1, val);
  else if (arr[mid] < val)
    return recursive_binary_search(arr, mid + 1, end, val);

  return -1;
}

int main() {
  int a[7] = {1, 3, 4, 5, 6, 7, 9};
  int target = 9;

  int result = binary_search(a, sizeof(a)/sizeof(a[0]), target);
  // int result = recursive_binary_search(a, 0, 6, target);

  if (result == -1)
    std::cout << "Not found!" << std::endl;
  else
    std::cout << "Found! index = " << result << std::endl;

  auto res = std::lower_bound(a, a+7, target);
  if (res == a || *res != 9)
    std::cout << "Not found!" << std::endl;
  else
    std::cout << "Found! index = " << (res - a) << std::endl;

  bool exist = std::binary_search(a, a+7, target);
  if (exist)
    std::cout << "Found!" << std::endl;
  else
    std::cout << "Not Found!" << std::endl;
  return 0;
}
