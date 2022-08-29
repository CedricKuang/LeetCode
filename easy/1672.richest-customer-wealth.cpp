/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            int curr_sum = 0;
            for (int j = 0; j < accounts[i].size(); j++)
                curr_sum += accounts[i][j];
            if (curr_sum > max)
                max = curr_sum;
        }
        return max;
    }
};
// @lc code=end

