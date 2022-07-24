/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double k = 0;
        if (coordinates[0][0] == coordinates[1][0])
            k = 30000;
        else
            k = double(coordinates[1][1] - coordinates[0][1]) / double(coordinates[1][0] - coordinates[0][0]);
        for (int i = 1; i < coordinates.size() - 1; i++)
        {
            double curr_k;
            if (coordinates[i][0] == coordinates[i + 1][0])
                curr_k = 30000;
            else
                curr_k = double(coordinates[i + 1][1] - coordinates[i][1]) / double(coordinates[i + 1][0] - coordinates[i][0]);
            if (curr_k != k)
                return false;
        }
        return true;
    }
};
// @lc code=end

