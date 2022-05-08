/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> table;
        for (int i = 0; i <= nums.size(); i++)
        {
            table.insert(i);
        }        
        for (int i = 0; i < nums.size(); i++)
        {
            table.erase(nums[i]);
        }
        unordered_set<int>::iterator it = table.begin();
        return *it;
    }
};
// @lc code=end

