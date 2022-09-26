/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target < nums[0])
            return 0;
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return (low + high) / 2 + 1;

                
    }
};
// @lc code=end

