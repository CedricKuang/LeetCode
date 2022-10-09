/*
 * @lc app=leetcode id=1314 lang=cpp
 *
 * [1314] Matrix Block Sum
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            dp[i][0] = mat[i][0];
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i][j-1] + mat[i][j];
        }
        for(int j = 0; j < n; j++)
            for(int i = 1; i < m; i++)
                dp[i][j] += dp[i-1][j];
        int r1,r2,l1,l2;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                r1 = max(0,i-K);
                r2 = min(m-1,i+K);
                l1 = max(0,j-K);
                l2 = min(n-1,j+K);
                mat[i][j] = dp[r2][l2];
                if(r1 > 0)
                    mat[i][j] -= dp[r1-1][l2];
                if(l1 > 0)
                    mat[i][j] -= dp[r2][l1-1];
                if(r1 > 0 && l1 > 0)
                    mat[i][j] += dp[r1-1][l1-1];
            }
        }
        return mat;
    }
};
// @lc code=end

