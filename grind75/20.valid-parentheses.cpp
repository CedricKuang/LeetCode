/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1)
            return false;
        stack<char> stk;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stk.push(s[i]);
            }
            else 
            {
                char left;
                if (s[i] == ')')
                    left = '(';
                else if (s[i] == '}')
                    left = '{';
                else
                    left = '[';
                if (stk.empty() || stk.top() != left)
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end

