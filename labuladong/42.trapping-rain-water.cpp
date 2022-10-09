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
        int n = height.size();
        vector<int> left_most(n);
        vector<int> right_most(n);
        left_most[0] = height[0];
        right_most[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
        {
            left_most[i] = max(height[i], left_most[i - 1]);
            right_most[n - 1 - i] = max(right_most[n - i], height[n - i - 1]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (min(left_most[i], right_most[i]) - height[i]);
        }
        return ans;
    }
};
// @lc code=end

