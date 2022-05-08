/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1)
            return 1;

        long long low_bound = 1;
        long long up_bound = n;
        while(low_bound != (up_bound))
        {
            if (isBadVersion((up_bound + low_bound)/2))
                up_bound = (up_bound + low_bound)/2;
            else
                low_bound = ((up_bound + low_bound)/2 + 1);
        }
        return up_bound;
    }
};
// @lc code=end

