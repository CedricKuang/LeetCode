/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            map<int, int>::iterator it = result.find(nums[i]);
            if (it == result.end())
                result.insert({nums[i], 1});
            else
                it->second++;
        }
        int major = nums.size() / 2;

        for (map<int, int>::iterator it = result.begin(); it != result.end(); it++)
        {
            if (it->second > major)
                return it->first;
        }
        return 0;
    }
};
// @lc code=end

