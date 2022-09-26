/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size())
        {
            if (nums[left] != nums[right])
            {
                left++;
                nums[left] = nums[right];
            }
            right++;
        }
        return left + 1;
    }
};
// @lc code=end

