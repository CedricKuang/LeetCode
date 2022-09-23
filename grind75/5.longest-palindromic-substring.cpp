/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string helper(string& s, int left, int right)
    {
        while (left >= 0 && right <= s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            string s1 = helper(s, i, i);
            // 以 s[i] 和 s[i+1] 为中心的最长回文子串
            string s2 = helper(s, i, i + 1);
            // res = longest(res, s1, s2)
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }
        return res;
    }
};
// @lc code=end

