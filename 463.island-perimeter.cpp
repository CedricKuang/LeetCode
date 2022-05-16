/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        int result = 0;
        for (int i = 0; i < row; i++)
        {
            for (int m = 0; m < column; m++)
            {
                if (grid[i][m] == 1)
                {
                    result += 4;

                    if (m > 0 && grid[i][m - 1] == 1)
                        result--;
                    if (m < column - 1 && grid[i][m + 1] == 1)
                        result--;
                    if (i > 0 && grid[i - 1][m] == 1)
                        result--;
                    if (i < row - 1 && grid[i + 1][m] == 1)
                        result--;
                }
            }
        }
        return result;
    }
};
// @lc code=end

