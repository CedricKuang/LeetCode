/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */

// @lc code=start
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 0 , minAns=0;
        for(int x : nums){
            ans+= x;
            if(ans < minAns)
                minAns = ans;
        }
        return -minAns+1;
    }
};
// @lc code=end

