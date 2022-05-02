/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            map<int, int>::iterator it = result.find(nums[i]);
            if (it != result.end())
            {
                if (abs(it->second - i) <= k)
                    return true;
            }
            result[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end

