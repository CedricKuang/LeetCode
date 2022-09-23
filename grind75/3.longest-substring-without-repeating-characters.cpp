/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1)
            return s.length();
        int left = 0;
        int right = 1;
        int max_ans = 1;
        unordered_map<char, int> table;
        table[s[0]] = 0;
        while (right < s.length())
        {
            if (table.count(s[right]) == 1 && table[s[right]] >= left)
            {
                left = table[s[right]] + 1;
                table[s[right]] = right;
            }
            else
            {
                table[s[right]] = right;
                max_ans = max(max_ans, right - left + 1);
            }
            right++;
        }
        return max_ans;
    }
};
// @lc code=end

