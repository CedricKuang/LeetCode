/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int top = nums.size() - 1;
        int bottom = 0;
        while (top >= bottom)
        {
            if (target > nums[(top + bottom) / 2])
                bottom = (top + bottom) / 2 + 1;
            else if (target < nums[(top + bottom) / 2])
                top = (top + bottom) / 2 - 1;
            else 
                return  (top + bottom) / 2;
        }
        return -1;

    }
};
// @lc code=end

