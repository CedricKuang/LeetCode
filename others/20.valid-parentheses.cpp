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
        stack<char> my_stack;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                my_stack.push(s[i]);
            else
            {
                if (my_stack.empty())
                    return false;
                char top = my_stack.top();
                my_stack.pop();
                if (s[i] == ')' && top != '(')
                    return false;
                else if (s[i] == '}' && top != '{')
                    return false;
                else if (s[i] == ']' && top != '[')
                    return false;
            }
        }
        return my_stack.empty();
    }
};
// @lc code=end

