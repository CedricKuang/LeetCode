/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int m = i + 1; m < nums.size(); m++)
            {
                if (nums[m] == nums[i])
                    ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

