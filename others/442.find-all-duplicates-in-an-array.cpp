/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr_index = abs(nums[i]) - 1;
            if (nums[curr_index] < 0)
                ans.push_back(abs(nums[i]));
            else
                nums[curr_index] = -nums[curr_index];
        }
        return ans;
    }
};
// @lc code=end

