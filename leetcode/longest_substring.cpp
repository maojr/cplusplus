// 3. Longest Substring Without Repeating Characters
// URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// Given a string, find the length of the longest substring without repeating characters.

// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution
{
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        std::vector<char> vec;
        for (size_t i = 0; i < s.size(); ++i) {
            std::vector<char>::iterator iter = std::find(vec.begin(), vec.end(), s[i]);
            if (iter == vec.end()) {
                vec.push_back(s[i]);
            } else {
                vec.erase(vec.begin(), iter+1);
                vec.push_back(s[i]);
            }
            if (vec.size() > result)
                result = vec.size();
        }
        return result;
    }

    int lengthOfLongestSubstring2(string s) {
        int result = 0;

        int map[256] = {0};
        int start = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (map[s[i]]) {
                if (i - start > result)
                    result = i - start;
                for (int j = start; j < i; ++j) {
                    if (s[j] == s[i]) {
                        start = j + 1;
                        break;
                    }
                    map[s[j]] = 0;
                }
            } else {
                map[s[i]] = 1;
            }
        }
        if (s.size() - start > result)
            result = s.size() - start;

        return result;
    }
};