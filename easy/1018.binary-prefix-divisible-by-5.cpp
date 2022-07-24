/*
 * @lc app=leetcode id=1018 lang=cpp
 *
 * [1018] Binary Prefix Divisible By 5
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:

    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int num;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            num = (num * 2 + nums[i]) % 5;
            res.push_back(num == 0);
        }
        
        return res;
    }
};
// @lc code=end

