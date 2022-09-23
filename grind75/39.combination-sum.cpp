/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    void backtrack(vector<int>& candidates, int start, int target, int sum)
    {
        if (sum == target)
        {
            res.push_back(track);
            return;
        }
        if (sum > target)
            return;
        for (int i = start; i < candidates.size(); i++)
        {
            track.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, i, target, sum);
            sum -= candidates[i];
            track.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0)
            return res;
        backtrack(candidates, 0, target, 0);
        return res;
    }
};
// @lc code=end

