/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                dup++;
            else
                dup = 1;
            
            if (dup == 3)
            {
                nums[i - 2] = 20000;
                dup--;
            }
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 20000)
                ans++;
            else    
                break;
        }
        return ans;
    }
};
// @lc code=end

