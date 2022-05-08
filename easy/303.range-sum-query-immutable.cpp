/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
#include <vector>
using namespace  std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        num_array = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++)
        {
            sum += num_array[i];
        }
        return sum;
    }
private:
    vector<int> num_array;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

