/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    unordered_set<int> has;

    void back_track(vector<int>& nums)
    {
        if (nums.size() == curr.size())
        {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (has.count(i) == 0)
            {
                has.insert(i);
                curr.push_back(nums[i]);
                back_track(nums);
                has.erase(i);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        back_track(nums);
        return ans;
    }
};
// @lc code=end

