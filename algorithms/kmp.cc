#include <iostream>
#include <vector>

// Knuth–Morris–Pratt algorithm
// http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
void kmpSearch(std::string s, std::string p) {
  int i = 0;
  int j = 0;

  // 求出Partial Match Table
  std::vector<int> table(p.size(), 0);
  for (int k = 1; k < p.size(); k++) {
    int m = table[k - 1];
    while (m > 0 && p[m] != p[k]) {
      m = table[m - 1];
    }
    if (p[m] == p[k]) {
      table[k] = m + 1;
    } else {
      table[k] = 0;
    }
  }

  while (i < s.size() && j < p.size()) {
    if (s[i] == p[j]) {
      i++;
      j++;
    } else {
      if (j == 0) {
        i++;
      } else {
        j = table[j - 1];
      }
    }
    if (j == p.size()) {
      std::cout << i - j << std::endl;
      j = table[j - 1];
    }
  }
}

void search(std::string s, std::string p) {
  int sLen = s.size();
  int pLen = p.size();
  int i = 0;
  int j = 0;
  while (i < sLen && j < pLen) {
    if (s[i] == p[j]) {
      i++;
      j++;
    } else {
      i = i - j + 1;
      j = 0;
    }
    if (j == pLen) {
      std::cout << i - j << std::endl;
      i = i - j + 1;
      j = 0;
    }
  }
}

int main() {
  std::string s = "abc123def123";
  kmpSearch(s, "123");
  search(s, "123");
  return 0;
}
