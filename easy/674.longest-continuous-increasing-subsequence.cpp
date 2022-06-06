/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
#include <vector>
using namespace std;


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int temp = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                temp++;
            else
            {
                if (temp > ans)
                    ans = temp;
                temp = 1;
            }
        }
        if (temp > ans)
            ans = temp;
        return ans;
    }
};
// @lc code=end

