/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = false;
        bool dec = false;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (!inc && !dec)
            {
                if (nums[i] > nums[i + 1])
                    dec = true;
                else if (nums[i] < nums[i + 1])
                    inc = true;
            }

            if (inc)
            {
                if (nums[i + 1] < nums[i])
                    return false;
            }
            else if (dec)
            {
                if (nums[i + 1] > nums[i])
                    return false;
            }
        }
        return true;

    }
};
// @lc code=end

