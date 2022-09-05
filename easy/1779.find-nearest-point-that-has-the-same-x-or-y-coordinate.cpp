/*
 * @lc app=leetcode id=1779 lang=cpp
 *
 * [1779] Find Nearest Point That Has the Same X or Y Coordinate
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_index = -1;
        int min_dis = INT_MAX;
        for (int i = 0; i < points.size(); i++)
        {
            if (x == points[i][0] || y == points[i][1])
            {
                if (abs(points[i][0] - x) + abs(points[i][1] - y) < min_dis)
                {
                    min_dis = abs(points[i][0] - x) + abs(points[i][1] - y);
                    min_index = i;
                }
            }
        }
        return min_index;
    }
};
// @lc code=end

