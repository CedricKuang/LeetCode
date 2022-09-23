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
        stack<int> my_stack;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int num2 = my_stack.top();
                my_stack.pop();
                int num1 = my_stack.top();
                my_stack.pop();
                if (tokens[i] == "+")
                {
                    my_stack.push(num1 + num2);
                }
                else if (tokens[i] == "-")
                {
                    my_stack.push(num1 - num2);
                }
                else if (tokens[i] == "*")
                {
                    my_stack.push(num1 * num2);
                }
                else
                    my_stack.push(num1 / num2);
            }
            else
            {
                my_stack.push(stoi(tokens[i]));
            }
        }
        return my_stack.top();
    }
};
// @lc code=end

