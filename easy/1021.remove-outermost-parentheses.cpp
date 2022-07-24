/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        if (s.empty() || s.length() == 2)
            return "";

        int left = 0;
        int left_most = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                left++;
            else if (s[i] == ')')
                left--;
            
            if (left == 0)
            {
                s.erase(i, 1);
                s.erase(left_most, 1);
                i -= 2;
                left = 0;
                left_most = i + 1;
            }
        }

        return s;
    }
};
// @lc code=end

