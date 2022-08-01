/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        vector<int> mapping(nums.size(), nums.size());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int m = i + 1; m <= i + nums[i] && m < nums.size(); m++)
            {
                if (i < mapping[m])
                    mapping[m] = i;
            }
        }

        int curr = nums.size() - 1; 
        while ( curr != 0 )
        {
            curr = mapping[curr];
            ans++;
        }


        return ans;
    }
};
// @lc code=end

