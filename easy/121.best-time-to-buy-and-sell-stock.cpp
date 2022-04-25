/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int profit = 0;
        int least = INT_MAX;
        int estimate = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < least)
                least = prices[i];
            estimate = prices[i] - least;
            if (estimate > profit)
                profit = estimate;
        }
        return profit;
    }
};
// @lc code=end

