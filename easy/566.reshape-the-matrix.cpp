/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c)
            return mat;

        vector<int> all;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int m = 0; m < mat[0].size(); m++)
                all.push_back(mat[i][m]);
        }

        vector<vector<int>> result;
        for (int i = 0; i < r; i++)
        {
            vector<int> row;
            for (int m = 0; m < c; m++)
            {
                row.push_back(all[i * c + m]);
            }
            result.push_back(row);
        }
        return result;
    }
};
// @lc code=end

