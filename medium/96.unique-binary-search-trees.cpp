/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                dp[1] = 1;
            else if (i == 2)
                dp[2] = 2;
            else
            {
                for (int j = 0; j <= i - 1; j++)
                {
                    if (j == 0 || j == i - 1)
                    {
                        dp[i] += dp[i - 1];
                    }
                    else
                    {
                        dp[i] += (dp[j] * dp[i - 1 - j]);
                    }
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

