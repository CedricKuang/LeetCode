/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        vector<int> dp(s.length() + 1);

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                stk.push(i);
                dp[i + 1] = 0;
            }
            else
            {
                if (!stk.empty())
                {
                    int left_index = stk.top();
                    stk.pop();
                    int len = 1 + i - left_index + dp[left_index];
                    dp[i + 1] = len;
                }
                else
                {
                    dp[i + 1] = 0;
                }
            }
        }


        int res = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

