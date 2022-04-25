/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (stk.empty())
                    return false;
                
                char top = stk.top();
                if ((s[i] == ')' && top == '(') 
                || (s[i] == ']' && top == '[')
                || (s[i] == '}' && top == '{'))
                    stk.pop();
                else
                    return false;
            }
        }

        return stk.empty();
    }
};
// @lc code=end

