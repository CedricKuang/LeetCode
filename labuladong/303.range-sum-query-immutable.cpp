/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        prefix_sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            prefix_sum.push_back(prefix_sum[i - 1] + nums[i]);
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
            return prefix_sum[right];
        else
            return prefix_sum[right] - prefix_sum[left - 1]; 
    }
private:
    vector<long> prefix_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

