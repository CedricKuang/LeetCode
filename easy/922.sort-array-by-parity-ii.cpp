/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }

        int i = 0, j = 0, m = 0;
        while (m != nums.size())
        {
            if (m % 2 == 0)
            {
                nums[m] = even[i];
                i++;
            }
            else
            {
                nums[m] = odd[j];
                j++;
            }
            m++;
        }
        return nums;
    }
};
// @lc code=end

