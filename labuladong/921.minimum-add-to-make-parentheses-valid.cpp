/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> my_stack;
        for (char c : s)
        {
            if (c == '(')
                my_stack.push('(');
            else
            {
                if (!my_stack.empty() && my_stack.top() == '(')
                    my_stack.pop();
                else
                    my_stack.push(')');
            }
        }
        return my_stack.size();
    }
};
// @lc code=end

