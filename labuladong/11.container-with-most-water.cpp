/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, rigth = height.size() - 1;
        int ans = 0;
        while (left < rigth)
        {
            ans = max(ans, min(height[left], height[rigth]) * (rigth - left));
            if (height[left] < height[rigth])
                left++;
            else
                rigth--;
        }
        return ans;
    }
};
// @lc code=end

