/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string temp = "";
        stack<string> stk;
        while (ss >> temp)
        {
            if (temp[0] == ' ')
                continue;
            stk.push(temp);
        }
        temp = "";
        while (!stk.empty())
        {
            temp += stk.top();
            stk.pop();
            if (!stk.empty())
                temp += " ";        
        }
        return temp;
    }
};
// @lc code=end

