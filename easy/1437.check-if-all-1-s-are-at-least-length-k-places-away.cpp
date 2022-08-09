/*
 * @lc app=leetcode id=1437 lang=cpp
 *
 * [1437] Check If All 1's Are at Least Length K Places Away
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_one = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (last_one == -1 || ((i - last_one - 1) >= k))
                {
                    last_one = i;
                }  
                else 
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

