/*
 * @lc app=leetcode id=1403 lang=cpp
 *
 * [1403] Minimum Subsequence in Non-Increasing Order
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int total_sum = 0;
        for (int i = 0; i < nums.size(); i++)
            total_sum += nums[i];
        int curr_sum = 0;
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            curr_sum += nums[i];
            ans.push_back(nums[i]);
            if (curr_sum > (total_sum - curr_sum))
                return ans;
        }
        return ans;
    }
};
// @lc code=end

