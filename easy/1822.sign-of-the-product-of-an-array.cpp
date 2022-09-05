/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                return 0;
            else if (nums[i] < 0)
                ans = -1 * ans;
        }     
        return ans;
    }
};
// @lc code=end

