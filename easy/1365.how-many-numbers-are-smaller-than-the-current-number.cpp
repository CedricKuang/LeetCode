/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        vector<int> ans;
        unordered_map<int, int> table;
        sort(sorted_nums.begin(), sorted_nums.end());
        for (int i = 0; i < sorted_nums.size(); i++)
        {
            unordered_map<int, int>::iterator it = table.find(sorted_nums[i]);
            if (it == table.end())
                table.insert(pair<int, int>(sorted_nums[i], i));
        }

        for (int i = 0; i < nums.size(); i++)
            ans.push_back(table[nums[i]]);
        return ans;
    }
};
// @lc code=end

