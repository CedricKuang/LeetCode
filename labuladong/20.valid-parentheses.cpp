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
        stack<char> my_stack;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                my_stack.push(c);
            }
            else
            {
                if (my_stack.empty())
                    return false;
                char top = my_stack.top();
                my_stack.pop();
                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[') )
                {
                    return false;
                }
            }
        }
        return my_stack.empty();
    }
};
// @lc code=end

