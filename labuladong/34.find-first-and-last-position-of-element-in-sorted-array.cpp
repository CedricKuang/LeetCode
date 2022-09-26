/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void find_min(vector<int>& ans, int low, int high, vector<int>& nums, int target)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target)
                high = mid - 1;
            else if (nums[mid] < target)
                low = mid + 1;
            else
            {
                ans[0] = mid;
                high = mid - 1;
            }
        }
    }
    void find_max(vector<int>& ans, int low, int high, vector<int>& nums, int target)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target)
                high = mid - 1;
            else if (nums[mid] < target)
                low = mid + 1;
            else
            {
                ans[1] = mid;
                low = mid + 1;
            }
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        vector<int> ans = {-1, -1};
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target)
                high = mid - 1;
            else if (nums[mid] < target)
                low = mid + 1;
            else
            {
                find_min(ans, low, high, nums, target);
                find_max(ans, low, high, nums, target);
                break;
            } 
        }
        return ans;
    }
};
// @lc code=end

