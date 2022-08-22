/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
            table[nums[i]]++;
        int m = 0;
        for (int i = 0; i <= 2; i++)
        {
            while (table[i] != 0)
            {
                table[i]--;
                nums[m] = i;
                m++;
            }
        }
    }
};
// @lc code=end

