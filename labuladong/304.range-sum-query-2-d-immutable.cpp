/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
#include <vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            prefix_sum.push_back({});
            for (int j = 0; j < n; j++)
                prefix_sum[i].push_back(0);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    prefix_sum[0][0] = matrix[0][0];
                else if (i == 0)
                    prefix_sum[0][j] = prefix_sum[0][j - 1] + matrix[0][j];
                else if (j == 0)
                    prefix_sum[i][0] = prefix_sum[i - 1][0] + matrix[i][0];
                else
                    prefix_sum[i][j] = matrix[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefix_sum[row2][col2];
        if (row1 != 0)
            sum -= prefix_sum[row1 - 1][col2];
        if (col1 != 0)
            sum -= prefix_sum[row2][col1 - 1];
        if (row1 != 0 && col1 != 0)
            sum += prefix_sum[row1 - 1][col1 - 1];
        return sum;
    }
private:
    int m, n;
    vector<vector<int>> prefix_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

