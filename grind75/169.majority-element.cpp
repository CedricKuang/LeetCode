/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = -1, cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
                c = nums[i];
            cnt += (nums[i] == c) ? 1 : -1;
        }
        return c;
    }
};
// @lc code=end

