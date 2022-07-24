/*
 * @lc app=leetcode id=1281 lang=cpp
 *
 * [1281] Subtract the Product and Sum of Digits of an Integer
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        int dup_n = n;
        while (dup_n > 0)
        {
            int digit = dup_n % 10;
            product *= digit;
            sum += digit;
            dup_n /= 10;
        }

        return product - sum;
        
        
    }
};
// @lc code=end

