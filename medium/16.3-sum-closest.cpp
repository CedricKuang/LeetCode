/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = 0;
        int min_diff = 200000;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size() - 1; i++)
        {
            int left = 0;
            int right = nums.size() - 1;
            while (left != i && right != i)
            {
                int diff = abs(nums[i] + nums[left] + nums[right] - target);
                if (diff < min_diff)
                {
                    min_diff = diff;
                    sum = nums[i] + nums[left] + nums[right];
                }

                if (nums[i] + nums[left] + nums[right] > target)
                    right--;
                else if (nums[i] + nums[left] + nums[right] < target)
                    left++;
                else
                    return nums[i] + nums[left] + nums[right];

            }
        }
        return sum;
    }
};
// @lc code=end

