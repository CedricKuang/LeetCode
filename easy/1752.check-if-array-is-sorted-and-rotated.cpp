/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        bool pivot = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == nums.size() - 1)
            {
                if (nums[0] < nums[i])
                {
                    if (pivot)
                        return false;
                    else
                        pivot = true;
                }
            }
            else
            {
                if (nums[i + 1] < nums[i])
                {
                    if (pivot)
                        return false;
                    else
                        pivot = true;
                }
            }
        }
        return true;
    }
};
// @lc code=end

