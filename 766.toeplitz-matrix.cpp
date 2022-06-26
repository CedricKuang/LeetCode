/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() - 1; i++)
        {
            for (int m = 0; m < matrix[0].size() - 1; m++)
            {
                if (matrix[i][m] != matrix[i + 1][m + 1])
                    return false;
            }
        }   
        return true;
    }
};
// @lc code=end

