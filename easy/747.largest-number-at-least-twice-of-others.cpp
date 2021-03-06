/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = nums[0];
        int index = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                index = i;
            }
                
        }

        for (int i = 0; i <nums.size(); i++)
        {
            if (i != index && nums[i] * 2 > max)
                return -1;
        }
        return index;
    }
};
// @lc code=end

