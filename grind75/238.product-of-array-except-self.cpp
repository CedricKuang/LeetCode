/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size());
        vector<int> post(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                pre[0] = 1;
                post[nums.size() - 1] = 1;
            }
            else
            {
                pre[i] = pre[i - 1] * nums[i - 1];
                post[nums.size() - 1 - i] = post[nums.size() - i] * nums[nums.size() - i];
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = pre[i] * post[i];
        }
        return nums;
    }
};
// @lc code=end

