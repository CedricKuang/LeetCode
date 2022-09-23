/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int upper = nums.size() - 1;
        while (low <= upper)
        {
            int mid = low + (upper - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                upper = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
        
    }
};
// @lc code=end

