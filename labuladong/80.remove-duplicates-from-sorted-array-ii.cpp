/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0, count = 0;
        while (right < nums.size())
        {
            if (nums[right] != nums[left])
            {
                left++;
                nums[left] = nums[right];
            }
            else if (left < right && count < 2)
            {
                left++;
                nums[left] = nums[right];
            }
            right++;
            count++;
            if (right < nums.size() && nums[right] != nums[right - 1])
                count = 0;

        }
        return left + 1;
        
    }
};
// @lc code=end

