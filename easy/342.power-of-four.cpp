/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1)
            return true;
        else if (n <= 0)
            return false;
        else if (n % 4 == 0)
            return isPowerOfFour(n / 4);
        else 
            return false;
        
    }
};
// @lc code=end

