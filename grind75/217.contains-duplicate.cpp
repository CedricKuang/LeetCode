/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            seen[nums[i]]++;
        }
        for (auto it = seen.begin(); it != seen.end(); it++)
        {
            if (it->second >= 2)
                return true;
        }
        return false;
    }
};
// @lc code=end

