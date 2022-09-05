/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
class Solution {
public:
    int subsetXORSum(vector<int>& n) {
        return accumulate(begin(n), end(n), 0, bit_or<int>()) << (n.size() - 1);
    }
};
// @lc code=end

