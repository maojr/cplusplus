#include <assert.h>
#include <iostream>

int brute_longest_common_substring(const std::string& str1,
                                   const std::string& str2) {
  int result = 0;
  for (int i = 0; i < str1.size(); ++i)
    for (int j = 0; j < str2.size(); ++j) {
      int n = i;
      int m = j;
      while (str1[n++] == str2[m++])
        ;
      result = n - i - 1 > result ? n - i - 1 : result;
    }
  return result;
}

int dynamic_longest_common_substring(const std::string& str1,
                                     const std::string& str2) {
  int result = 0;
  int dp[str1.size() + 1][str2.size() + 1];

  for (int i = 0; i < str1.size() + 1; ++i)
    for (int j = 0; j < str2.size() + 1; ++j) dp[i][j] = 0;

  for (int i = 1; i < str1.size() + 1; ++i)
    for (int j = 1; j < str2.size() + 1; ++j) {
      if (str1[i - 1] == str2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = 0;
      if (dp[i][j] > result) result = dp[i][j];
    }
  return result;
}

void TEST1() {
  std::string str1 = "xyzabc";
  std::string str2 = "abd";
  assert(brute_longest_common_substring(str1, str2) ==
         dynamic_longest_common_substring(str1, str2));
}

void runAllTests() { TEST1(); }

int main(int argc, char const* argv[]) {
  runAllTests();
  return 0;
}
