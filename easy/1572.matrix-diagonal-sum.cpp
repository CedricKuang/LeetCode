/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            ans += mat[i][i];
        }

        for (int i = mat.size() - 1, j = 0; i >= 0; i--, j++)
        {
            ans += mat[j][i];
        }

        if (mat.size() % 2 == 1)
        {
            ans -= mat[mat.size() / 2][mat.size() / 2];
        }
        return ans;
    }
};
// @lc code=end

