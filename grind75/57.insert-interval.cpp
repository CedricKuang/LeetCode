/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int overlapped_min = newInterval[0];
        int overlapped_max = newInterval[1];
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][1] < newInterval[0])
            {
                ans.push_back(intervals[i]);
            }
            else if (intervals[i][0] > newInterval[1])
            {
                if (overlapped_max != -1 && overlapped_min != -1)
                {
                    ans.push_back({overlapped_min, overlapped_max});
                    overlapped_max = -1;
                    overlapped_min = -1;
                }         
                ans.push_back(intervals[i]);
                
            }
            else if (intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1])
            {
                overlapped_min = min(overlapped_min, intervals[i][0]);
                overlapped_max = max(overlapped_max, intervals[i][1]);
            }
        }
        if (overlapped_max != -1 && overlapped_min != -1)
            ans.push_back({overlapped_min, overlapped_max});
        return ans;
    }
};
// @lc code=end

