/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int close = __INT_MAX__;
    int ans = __INT_MAX__;
    void two_sum(vector<int>& nums, int i, int target)
    {
        int left = 0, right = nums.size() - 1;
        if (right == i)
            right--;
        if (left == i)
            left++;
        while (left < right)
        {
            if (abs(nums[left] + nums[right] - target) < close)
            {
                close = abs(nums[left] + nums[right] - target);
                ans = nums[left] + nums[right] + nums[i];
            }
            if (nums[left] + nums[right] > target)
            {
                right--;
            }
            else
            {
                left++;
            }

            if (right == i)
                right--;
            if (left == i)
                left++;
        }
        
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            two_sum(nums, i, target - nums[i]);
        }
        return ans;
    }
};
// @lc code=end

