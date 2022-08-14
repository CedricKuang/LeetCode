/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int dir = 0;
        int p = 0, q = 0;
        for (int i = 1; i <= n * n; i++)
        {
            ans[p][q] = i;
            if (dir == 0)
            {
                q++;
                if (q == n || ans[p][q] != 0)
                {
                    q--;
                    p++;
                    dir = 1;
                }
            }
            else if (dir == 1)
            {
                p++;
                if (p == n || ans[p][q] != 0)
                {
                    p--;
                    q--;
                    dir = 2;
                }
            }
            else if (dir == 2)
            {
                q--;
                if (q < 0 || ans[p][q] != 0)
                {
                    q++;
                    p--;
                    dir = 3;
                }
            }
            else
            {
                p--;
                if (p < 0 || ans[p][q] != 0)
                {
                    p++;
                    q++;
                    dir = 0;
                }
            }

        }
        return ans;
    }
};
// @lc code=end

