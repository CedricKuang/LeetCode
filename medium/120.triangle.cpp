/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle[triangle.size() - 1].size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if(j == 0)
                    dp[i][j] = dp[i- 1][j] + triangle[i][j];
                else if (j == triangle[i].size() - 1)
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
        }

        int ans = dp[n - 1][0];
        for (int i = 1; i < n; i++)
            ans = min(ans, dp[n - 1][i]);
        return ans;
    }
};
// @lc code=end

