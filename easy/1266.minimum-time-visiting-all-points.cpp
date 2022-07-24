/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        vector<int> curr = points[0];
        int time = 0;
        for (int i = 1; i < points.size(); i++)
        {
            while (points[i][0] != curr[0] || points[i][1] != curr[1])
            {
                // cout << curr[0] << " " << curr[1] << endl;
                // cout << points[i][0] << " " << points[i][1] << endl;
                if (points[i][0] > curr[0] && points[i][1] > curr[1])
                {
                    curr[0]++;
                    curr[1]++;
                }
                else if (points[i][0] < curr[0] && points[i][1] < curr[1])
                {
                    curr[0]--;
                    curr[1]--;
                }
                else if (points[i][0] > curr[0] && points[i][1] < curr[1])
                {
                    curr[0]++;
                    curr[1]--;
                }
                else if (points[i][0] < curr[0] && points[i][1] > curr[1])
                {
                    curr[0]--;
                    curr[1]++;
                }
                else if (points[i][0] > curr[0])
                {
                    curr[0]++;
                }
                else if (points[i][0] < curr[0])
                {
                    curr[0]--;
                }
                else if (points[i][1] > curr[1])
                {
                    curr[1]++;
                }
                else
                {
                    curr[1]--;
                }
                time++;
            }
        }
        return time;
    }
};
// @lc code=end

