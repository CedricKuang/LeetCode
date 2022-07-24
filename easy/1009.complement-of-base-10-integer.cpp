/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        int index = 1;
        int ans = 0;
        while (n != 0)
        {
            int mod = n % 2;
            if (mod == 0)
                ans += index;
            index *= 2;
            n /= 2; 
        }
        return ans;
    }
};
// @lc code=end

