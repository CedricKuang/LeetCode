/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length(); i++)
        {
            if (!isalpha(s[i]) && !isdigit(s[i]))
            {
                s.erase(i, 1);
                i--;
            }
            else if (isupper(s[i]))
                s[i] = tolower(s[i]);
        }


        int m = 0;
        int n = s.length() - 1;
        while (m <= n)
        {
            if (s[m] != s[n])
                return false;
            m++;
            n--;
        }
        return true;
    }
};
// @lc code=end

