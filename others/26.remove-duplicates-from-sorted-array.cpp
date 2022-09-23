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
        if (nums.size() == 1)
            return 1;
        int left = 0;
        int right = 0;
        while (right < nums.size())
        {
            if (nums[right] != nums[left])
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

