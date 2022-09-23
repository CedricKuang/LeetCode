/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;
        int n = height.size();
        int res = 0;

        int lmax[n];
        int rmax[n];

        lmax[0] = height[0];
        rmax[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++)
        {
            lmax[i] = max(height[i], lmax[i - 1]);
            rmax[n - i - 1] = max(height[n - i - 1], rmax[n - i]);
        }
        for (int i = 0; i < n; i++)
        {
            res += (min(lmax[i], rmax[i]) - height[i]);
        }

        return res;
    }
};
// @lc code=end

