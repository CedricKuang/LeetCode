/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoSum;
        vector<int>::iterator it = nums.begin();
        for (int a = 0; it != nums.end(); it++, a++)
        {
            vector<int>::iterator it2 = it;
            it2++;
            for (int b = (a + 1); it2 != nums.end(); it2++, b++)
            {
                if (*it + *it2 == target)
                {
                    twoSum.push_back(a);
                    twoSum.push_back(b);
                    return twoSum;
                }
            }
        }
        return twoSum;
    }
};
// @lc code=end

