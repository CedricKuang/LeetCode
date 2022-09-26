/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;

        while (right < nums.size())
        {
            if (nums[right] != 0)
            {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;            
            }
            right++;
        }
    }
};
// @lc code=end

