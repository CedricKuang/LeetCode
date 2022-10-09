/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> my_stack;
        for (string s : tokens)
        {
            if (s == "+")
            {
                long a = my_stack.top();
                my_stack.pop();
                long b = my_stack.top();
                my_stack.pop();
                my_stack.push(a + b);
            }
            else if (s == "-")
            {
                long a = my_stack.top();
                my_stack.pop();
                long b = my_stack.top();
                my_stack.pop();
                my_stack.push(b - a);
            }
            else if (s == "*")
            {
                long a = my_stack.top();
                my_stack.pop();
                long b = my_stack.top();
                my_stack.pop();
                my_stack.push(a * b);
            }
            else if (s == "/")
            {
                long a = my_stack.top();
                my_stack.pop();
                long b = my_stack.top();
                my_stack.pop();
                my_stack.push(b / a);
            }
            else
            {
                my_stack.push(stoi(s));
            }
        }
        return my_stack.top();

        }
};
// @lc code=end

