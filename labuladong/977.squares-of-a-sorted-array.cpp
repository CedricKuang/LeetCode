/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1, i = n - 1;
        while (i >= 0)
        {
            if (abs(nums[left]) > abs(nums[right]))
            {
                ans[i] = nums[left];
                left++;
            }
            else 
            {
                ans[i] = nums[right];
                right--;
            }
            i--;
        }       

        for (int i = 0; i < n; i++)
            ans[i] = ans[i] * ans[i];
        return ans;
    }
};
// @lc code=end

