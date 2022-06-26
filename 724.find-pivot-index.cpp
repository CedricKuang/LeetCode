/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right_sum = 0;
        int left_sum = 0;
        for (int i = 0; i < nums.size(); i++)
            right_sum += nums[i];
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0)
                left_sum += nums[i - 1];
            right_sum -= nums[i];
            if (left_sum == right_sum)
                return i;
        }
        return -1;
    }
};
// @lc code=end

