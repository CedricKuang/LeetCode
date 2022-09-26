/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, max_ans = 0;
        unordered_set<char> window;
        while (right < s.length())
        {
            if (window.count(s[right]) == 1)
            {
                while (window.count(s[right]) == 1)
                {
                    window.erase(s[left]);
                    left++;
                }
            }
            window.insert(s[right]);
            max_ans = max(max_ans, right - left + 1);
            right++;
        }
        return max_ans;
    }
};
// @lc code=end

