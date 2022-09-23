/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // special algorithm:

        // if (prices.size() == 1)
        //     return 0;
        // int max_prof = 0;
        // int prev = prices[0];
        // for (int i = 1; i < prices.size(); i++)
        // {
        //     if (prices[i] - prev > max_prof)
        //         max_prof = prices[i] - prev;
        //     if (prev > prices[i])
        //         prev = prices[i];
        // }
        // return max_prof;

        // dp:
        int n = prices.size();
        int dp[n][2];
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
            }
            else
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], -prices[i]);
            }

        }
        return dp[n - 1][0];
    }
};
// @lc code=end

