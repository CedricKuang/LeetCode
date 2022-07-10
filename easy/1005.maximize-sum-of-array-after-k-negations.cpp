/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int get_sum(vector<int>& nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans += nums[i];
        return ans;
    }

    int find_min(vector<int>& nums)
    {
        int min = nums[0];
        int min_index = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < min)
            {
                min = nums[i];
                min_index = i;
            }
                
        }
        return min_index;
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++)
        {
            int index = find_min(nums);
            nums[index] = -nums[index];
        }
        return get_sum(nums);
    }
};
// @lc code=end

