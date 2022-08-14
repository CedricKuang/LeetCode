/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        set<pair<int, int>> table;
        int i = 0, j = 0;
        int dir = 0;
        while (spiral.size() != (matrix.size() * matrix[0].size()))
        {
            spiral.push_back(matrix[i][j]);
            table.insert({i, j});
            if (dir == 0)
            {
                j++;
                if (j == matrix[0].size() || table.count({i, j}) > 0)
                {
                    j--;
                    i++;
                    dir = 1;
                }
            }
            else if (dir == 1)
            {
                i++;
                if (i == matrix.size() || table.count({i, j}) > 0)
                {
                    i--;
                    j--;
                    dir = 2;
                }
            }
            else if (dir == 2)
            {
                j--;
                if (j < 0 || table.count({i, j}) > 0)
                {
                    j++;
                    i--;
                    dir = 3;
                }
            }
            else
            {
                i--;
                if (i < 0 || table.count({i, j}) > 0)
                {
                    i++;
                    j++;
                    dir = 0;
                }
            }
        }
        return spiral;
    }
};
// @lc code=end

