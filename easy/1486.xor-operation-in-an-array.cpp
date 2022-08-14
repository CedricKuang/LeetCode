/*
 * @lc app=leetcode id=1486 lang=cpp
 *
 * [1486] XOR Operation in an Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            nums.push_back(start + 2 * i);
        }

        int ans = nums[0];
        for (int i = 1; i < n; i++)
        {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
// @lc code=end

