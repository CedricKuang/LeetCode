/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        vector<int> dp(amount + 1);
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i] > amount)
                continue;
            dp[coins[i]]++;
        }

        for (int i = 1; i <= amount; i++)
        {
            if (dp[i] == 1)
                continue;
            int min_amount = INT_MAX;
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] > i)
                    continue;
                if (dp[i - coins[j]] != 0)
                    min_amount = min(min_amount, dp[i - coins[j]]);
            }
            if (min_amount != INT_MAX)
                dp[i] = min_amount + 1;
        }
        if (dp[amount] == 0)
            return -1;
        return dp[amount];
    }
};
// @lc code=end

