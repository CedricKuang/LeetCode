/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /* this works but too slow O(n^2)*/
        // int sub_max = nums[0];
        // int real_max = nums[0];
        // vector<int>::iterator it1 = nums.begin();
        // for (; it1 != nums.end(); it1++ )
        // {
        //     vector<int>::iterator it2 = it1;
        //     it2++;
        //     int sum = *it1;
        //     sub_max = sum;
        //     for (; it2 != nums.end(); it2++)
        //     {
        //         sum += *it2;
        //         if(sum > sub_max)
        //         {
        //             sub_max = sum;
        //         }
        //     }
        //     if (sub_max > real_max)
        //     {
        //         real_max = sub_max;
        //     }
        // }
        // return real_max;

        int MAX = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            MAX = max(sum, MAX);
            if(sum < 0) sum = 0;
        }
        return MAX;
    }
};
// @lc code=end

