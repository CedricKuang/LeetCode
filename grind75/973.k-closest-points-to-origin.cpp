/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2)
    {
        long double dis1 = sqrt(pow(v1[0], 2) + pow(v1[1], 2));
        long double dis2 = sqrt(pow(v2[0], 2) + pow(v2[1], 2));
        return dis1 < dis2;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), compare);
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(points[i]);
        }
        return ans;
    }
};
// @lc code=end

