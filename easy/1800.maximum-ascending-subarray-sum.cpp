/*
 * @lc app=leetcode id=1800 lang=cpp
 *
 * [1800] Maximum Ascending Subarray Sum
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int curr_sum = nums[0];
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                curr_sum += nums[i];
            }
            else
                curr_sum = nums[i];
            
            if (curr_sum > max_sum)
                max_sum = curr_sum;
        }
        return max_sum;
    }
};
// @lc code=end

