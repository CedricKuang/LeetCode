/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while (num != 0)
        {
            if (num % 2== 0)
                num /= 2;
            else
                num--;
            ans++;
        }
        return ans;
    }
};
// @lc code=end

