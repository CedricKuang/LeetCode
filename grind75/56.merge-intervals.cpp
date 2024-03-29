/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2)
    {
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > ans.back()[1])
                ans.push_back(intervals[i]);
            else
            {
                ans.back()[1] = intervals[i][1] > ans.back()[1] ? intervals[i][1] : ans.back()[1];
            }
        }
        return ans;
    }
};
// @lc code=end

