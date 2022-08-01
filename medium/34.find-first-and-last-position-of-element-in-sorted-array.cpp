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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int low = 0, high = nums.size() - 1, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {                 
                int temp_mid = mid;
                while (temp_mid <= high && nums[temp_mid] == target)
                {
                    ans[1] = temp_mid;
                    temp_mid++;
                }
                temp_mid = mid;
                while (temp_mid >= low && nums[temp_mid] == target)
                {
                    ans[0] = temp_mid;
                    temp_mid--;
                }
                break;
            }
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;

        }
        return ans;
    }
};
// @lc code=end

