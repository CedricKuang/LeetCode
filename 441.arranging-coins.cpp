/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int row = 0;
        while (n > 0)
        {
            n = n - (row + 1);
            if (n >= 0)
                row++;
        }

        return row;
    }
};
// @lc code=end

