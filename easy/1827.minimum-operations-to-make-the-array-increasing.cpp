/*
 * @lc app=leetcode id=1827 lang=cpp
 *
 * [1827] Minimum Operations to Make the Array Increasing
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                continue;
            else
            {
                ans += (nums[i - 1] - nums[i] + 1);
                nums[i] = nums[i - 1] + 1;
            }
                
        }        
        return ans;
    }
};
// @lc code=end

