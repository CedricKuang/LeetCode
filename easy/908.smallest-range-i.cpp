/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxv = *max_element(A.begin(),A.end());
        int minv = *min_element(A.begin(),A.end());
        return max(0,maxv-K-minv-K);
    }
};
// @lc code=end

