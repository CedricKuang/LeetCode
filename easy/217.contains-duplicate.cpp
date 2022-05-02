/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> record;
        for (int i = 0; i < nums.size(); i++)
        {
            if (record.find(nums[i]) != record.end())
                return true;
            else
                record[nums[i]] = 1;
        }
        return false;
    }
};
// @lc code=end

