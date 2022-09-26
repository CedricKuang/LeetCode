/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 */

// @lc code=start
class Solution {
public:
    long trailingZeroes(long n)
    {
        long res = 0;
        for (long d = n; d / 5 > 0; d = d / 5)
        {
            res += d / 5;
        }
        return res;
    }
    long left_bound(int target)
    {
        long lo = 0, hi = __LONG_LONG_MAX__;
        while (lo < hi)
        {
            long mid = lo + (hi - lo) / 2;
            if (trailingZeroes(mid) < target)
            {
                lo = mid + 1;
            }
            else if (trailingZeroes(mid) > target)
            {
                hi = mid;
            }
            else
                hi = mid;
        }
        return lo;
        
    }
    long right_bound(int target)
    {
        long lo = 0, hi = __LONG_LONG_MAX__;
        while (lo < hi)
        {
            long mid = lo + (hi - lo) / 2;
            if (trailingZeroes(mid) < target)
            {
                lo = mid + 1;
            }
            else if (trailingZeroes(mid) > target)
            {
                hi = mid;
            }
            else
                lo = mid + 1;
        }
        return lo - 1;
        
    }
    int preimageSizeFZF(int k) {
        return (int)(right_bound(k) - left_bound(k) + 1);
    }
};
// @lc code=end

