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
        vector<int> prefix(nums.size());
        prefix[0] = 1;
        vector<int> suffix(nums.size());
        suffix[nums.size() - 1] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = nums[i - 1] * prefix[i - 1];
            suffix[nums.size() - 1 - i] = nums[nums.size() - i] * suffix[nums.size() - i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = prefix[i] * suffix[i];
        }
        return nums;
    }
};
// @lc code=end

