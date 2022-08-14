/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return ((nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1));        
    }
};
// @lc code=end

