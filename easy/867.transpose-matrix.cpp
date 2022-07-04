/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            vector<int> row;
            for (int m = 0; m < matrix.size(); m++)
            {
                row.push_back(matrix[m][i]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
// @lc code=end

