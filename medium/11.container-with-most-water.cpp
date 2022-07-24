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
        int left = 0;
        int right = height.size() - 1;
        int max = 0;
        while (left != right)
        {
            int area = (right - left) * min(height[left], height[right]);
            if (area > max)
                max = area;
            
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max;
    }
};
// @lc code=end

