/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int right = 0, left = 0;
        
        while (right < nums.size())
        {
            if (nums[right] != val)
            {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }
        return left;
    }
};
// @lc code=end

