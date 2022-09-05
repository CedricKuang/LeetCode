/*
 * @lc app=leetcode id=1748 lang=cpp
 *
 * [1748] Sum of Unique Elements
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
            table[nums[i]]++;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (table[nums[i]] == 1)
                ans += nums[i];
        }
        return ans;
    }
};
// @lc code=end

