/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> ans = matrix;
        vector<int> row_zeros(matrix[0].size());
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    ans[i] = row_zeros;
                    for (int m = 0; m < matrix.size(); m++)
                        ans[m][j] = 0;
                }
            }
        }
        matrix = ans;
    }
};
// @lc code=end

