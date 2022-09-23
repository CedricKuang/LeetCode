/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, unordered_set<int>> table;
        for (int i = 0; i < nums.size(); i++)
        {
            table[nums[i]].insert(i);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (table.count(target - nums[i]) == 1)
            {
                if (table[target - nums[i]].count(i) == 0)
                {
                    return {i, *table[target - nums[i]].begin()};
                }
                else if (table[target - nums[i]].size() >= 2)
                {   
                    auto it = table[target - nums[i]].begin();
                    auto it2 = table[target - nums[i]].begin();
                    it2++;
                    return {*it, *it2};
                }
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

