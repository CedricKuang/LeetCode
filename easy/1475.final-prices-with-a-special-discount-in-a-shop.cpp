/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for (int i = 0; i < prices.size(); i++)
        {
            int m = i + 1;
            for (; m < prices.size(); m++)
            {
                if (prices[m] <= prices[i])
                    break;
            }

            if (m != prices.size())
                ans.push_back(prices[i] - prices[m]);
            else
                ans.push_back(prices[i]);

        }
        return ans;
    }
};
// @lc code=end

