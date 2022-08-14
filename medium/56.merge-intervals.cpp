/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <vector>
using namespace std;

bool sort_start(vector<int>& i1, vector<int>& i2)
{
    return i1[0] < i2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sort_start);
        vector<vector<int>> ans;
        vector<int> curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= curr[1])
            {
                if (intervals[i][1] > curr[1])
                    curr[1] = intervals[i][1];
            }
            else
            {
                ans.push_back(curr);
                curr[0] = intervals[i][0];
                curr[1] = intervals[i][1];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};
// @lc code=end

