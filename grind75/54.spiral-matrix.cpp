/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int count = 0;
        // 0: right, 1: down, 2: left, 3: up
        int state = 0;
        int i = 0, j = 0, rows = matrix.size(), cols = matrix[0].size();
        while (count < rows * cols)
        {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = -111;
            count++;
            // cout << count << " " << state << endl;
            if (state == 0)
            {
                if (j < cols - 1 && matrix[i][j + 1] != -111)
                {
                    j++;
                }
                else if (j == cols - 1 || matrix[i][j + 1] == -111)
                {
                    state = 1;
                    i++;
                }
            }
            else if (state == 1)
            {
                if (i < rows - 1 && matrix[i + 1][j] != -111)
                {
                    i++;
                }
                else if (i == rows - 1 || matrix[i + 1][j] == -111)
                {
                    state = 2;
                    j--;
                }
            }
            else if (state == 2)
            {
                if (j > 0 && matrix[i][j - 1] != -111)
                {
                    j--;
                }
                else if (j == 0 || matrix[i][j - 1] == -111)
                {
                    state = 3;
                    i--;
                }
            }
            else if (state == 3)
            {
                if (i > 0 && matrix[i - 1][j] != -111)
                {
                    i--;
                }
                else if (i == 0 || matrix[i - 1][j] == -111)
                {
                    state = 0;
                    j++;
                }
            }

        }
        return ans;
    }
};
// @lc code=end

