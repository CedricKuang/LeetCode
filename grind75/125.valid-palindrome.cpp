/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string new_s = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
                new_s += tolower(s[i]);
            else if (isdigit(s[i]))
                new_s += s[i];
        }

        for (int i = 0; i < new_s.length() / 2; i++)
        {
            if (new_s[i] != new_s[new_s.length() - i - 1])
                return false;
        }
        return true;
    }
};
// @lc code=end

