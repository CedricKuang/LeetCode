/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> track;
    void back_track(int index, vector<int>& nums)
    {
        ans.push_back(track);
        for (int i = index; i < nums.size(); i++)
        {
            track.push_back(nums[i]);
            back_track(i + 1, nums);
            track.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        back_track(0, nums);
        return ans;
    }
};
// @lc code=end

