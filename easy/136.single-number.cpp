/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_set<int>::iterator it = result.find(nums[i]);
            if (it == result.end())
                result.insert(nums[i]);
            else
                result.erase(it);
        }
        unordered_set<int>::iterator it = result.begin();
        return *it;
    }
};
// @lc code=end

