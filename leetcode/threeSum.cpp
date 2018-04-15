// Given an array nums of n integers, are there elements a, b, c in nums such
// that a + b + c = 0? Find all unique triplets in the array which gives the sum
// of zero.

// Note:
// The solution set must not contain duplicate triplets.
// Example:

// Given array nums = [-1, 0, 1, 2, -1, -4],
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    // -4, -1, -1, 0, 1, 2
    for (size_t i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      size_t j = i + 1;
      size_t k = nums.size() - 1;
      while (j < k) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          ++j;
          continue;
        }
        if (k < nums.size() - 1 && nums[k] == nums[k + 1]) {
          --k;
          continue;
        }
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          std::vector<int> v = {nums[i], nums[j], nums[k]};
          result.push_back(v);
          ++j;
        } else if (sum > 0) {
          --k;
        } else {
          ++j;
        }
      }
    }
    return result;
  }
};
