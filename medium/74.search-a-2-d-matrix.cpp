/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int curr_x = matrix[0].size() - 1;
        int curr_y = 0;

        while (curr_x >= 0 && curr_y < matrix.size())
        {
            if (target == matrix[curr_y][curr_x])
                return true;
            else if (target > matrix[curr_y][curr_x])
                curr_y++;
            else
                curr_x--;
        }
        return false;
    }
};
// @lc code=end

