// https://leetcode.com/problems/single-number-iii/description
//
// Given an array of numbers nums, in which exactly two elements appear only once
// and all the other elements appear exactly twice. Find the two elements that appear only once.

// For example:

// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

// Note:
// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity.
// Could you implement it using only constant space complexity?

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // accepted
    vector<int> static singleNumber(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> map;

        for(auto& num : nums)
            map[num] = map[num] + 1;

        for(auto& num : nums)
            if (map[num] == 1)
                result.push_back(num);

        return result;
    }

    vector<int> static singleNumber_xor(vector<int>& nums) {
        vector<int> result(2, 0);

        int xor_result = 0;
        for(auto& num : nums)
            xor_result ^= num;

        int diff_bit = xor_result & ~(xor_result - 1);

        for (auto& num : nums)
            if ((num & diff_bit) != 0)
                result[0] ^= num;
            else
                result[1] ^= num;

        return result;
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 1, 3, 2, 5};
    // std::vector<int> results = Solution::singleNumber(nums);
    std::vector<int> results = Solution::singleNumber_xor(nums);

    for (auto& result : results)
        std::cout << result << std::endl;

    return 0;
}
