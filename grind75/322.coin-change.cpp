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
        vector<int> dp(amount + 1, 0);
        unordered_set<int> used;
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i] > amount)
                continue;
            else
            {
                dp[coins[i]]++;
                used.insert(coins[i]);
            }
        }
        
        for (int i = 1; i <= amount; i++)
        {
            if (used.count(i) == 0)
            {
                int min_changes = INT_MAX;
                for (int j = 0; j < coins.size(); j++)
                {
                    if (i < coins[j])
                        continue;
                    if (dp[i - coins[j]] != 0)
                        min_changes = min(min_changes, dp[i - coins[j]]);
                }
                if (min_changes != INT_MAX)
                    dp[i] = min_changes + 1;
            }
        }
        // for (int i = 1; i <= amount; i++)
        //     // cout << dp[i] << endl;

        if (dp[amount] == 0)
            return -1;
        else
            return dp[amount];

    }
};
// @lc code=end

