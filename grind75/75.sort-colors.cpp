/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // initialize variables:
        int low = 0, mid = 0, high = nums.size() - 1;
        
        // logic:
        while(mid <= high)
        {
            switch(nums[mid])
            {
                case 0: swap(nums[low++], nums[mid++]); break;
                
                case 1: mid++; break;
                
                case 2: swap(nums[mid], nums[high--]); break;
            }
        }
             
    }
};
// @lc code=end

