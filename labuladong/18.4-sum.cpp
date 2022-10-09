/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> nSum(vector<int>& nums, int n, int start, long target)
    {
        int sz = nums.size();
        vector<vector<int>> ans;

        if (n < 2 || sz < n)
            return ans;
        if (n == 2)
        {
            int lo = start, hi = sz - 1;
            while (lo < hi)
            {
                long sum = nums[lo] + nums[hi];
                int left = nums[lo], right = nums[hi];
                if (sum < target)
                {
                    while (lo < hi && nums[lo] == left)
                    {
                        lo++;
                    }
                }
                else if (sum > target)
                {
                    while (lo < hi && nums[hi] == right)
                    {
                        hi--;
                    }
                }
                else
                {
                    ans.push_back({left, right});
                    while (lo < hi && nums[lo] == left)
                    {
                        lo++;
                    }
                    while (lo < hi && nums[hi] == right)
                    {
                        hi--;
                    }
                }
            }
        }
        else
        {
            for (int i = start; i < sz; i++)
            {
                vector<vector<int>> sub = nSum(nums, n - 1, i + 1, target - nums[i]);
                for (vector<int>& arr : sub)
                {
                    arr.push_back(nums[i]);
                    ans.push_back(arr);
                }
                while (i < sz - 1 && nums[i] == nums[i + 1])
                {
                    i++;
                }
                
            }
        }
        return ans;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return nSum(nums, 4, 0, target);
    }
};
// @lc code=end

