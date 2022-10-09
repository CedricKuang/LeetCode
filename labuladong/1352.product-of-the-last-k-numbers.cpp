/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start
#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    ProductOfNumbers() {
        nums.push_back(1);
    }
    
    void add(int num) {
        if (num == 0)
        {
            nums.clear();
            nums.push_back(1);
            return;
        }
        int n = nums.size();
        nums.push_back(nums[n - 1] * num);
    }
    
    int getProduct(int k) {
        int n = nums.size();
        if (k > n - 1)
        {
            return 0;
        }
        return nums[n - 1] / nums[n - k - 1];
    }
private:
    vector<int> nums;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

