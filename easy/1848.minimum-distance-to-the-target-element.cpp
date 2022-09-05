/*
 * @lc app=leetcode id=1848 lang=cpp
 *
 * [1848] Minimum Distance to the Target Element
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = __INT_MAX__;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                if (abs(i - start) < ans)
                    ans = abs(i - start);
            }
        }
        return ans;
    }
};
// @lc code=end

