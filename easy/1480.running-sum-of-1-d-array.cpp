/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int curr_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            ans.push_back(curr_sum);
        }        
        return ans;
    }
};
// @lc code=end

