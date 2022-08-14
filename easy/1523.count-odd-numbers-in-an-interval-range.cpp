/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

// @lc code=start
class Solution {
public:
    int countOdds(int low, int high) {
        if (low % 2 == 0 && high % 2 == 0)
            return (high - low) / 2;
        else
            return (high - low) / 2 + 1;
    }
};
// @lc code=end

