/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0, j = grid[0].size() - 1; i != grid.size(), j >= 0; j--)
        {
            while (i != grid.size() && grid[i][j] >= 0)
                i++;
            ans += (grid.size() - i);
        }
        return ans;
    }
};
// @lc code=end

