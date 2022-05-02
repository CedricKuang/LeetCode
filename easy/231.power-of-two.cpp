/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        else if (n == 1)
            return true;

        if (n % 2 == 0)
            return isPowerOfTwo(n / 2);
        else
            return false;
    }
};
// @lc code=end

