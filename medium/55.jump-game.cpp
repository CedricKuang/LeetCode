/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, minjump = 0;
        for(i = nums.size()-2; i >= 0; i--){
            minjump++;
            if(nums[i] >= minjump)
			    minjump = 0;
        }
        if(minjump == 0) 
		    return true;
        else 
		    return false;
    }
};
// @lc code=end

