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
        int length = right;
        int max_area = 0;
        while (left < right)
        {
            int curr_area = min(height[left], height[right]) * length;
            if (curr_area > max_area)
                max_area = curr_area;
            
            if (height[left] > height[right])
                right--;
            else 
                left++;
            length--;
        }
        return max_area;
    }
};
// @lc code=end

