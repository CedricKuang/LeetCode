/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = digits.size() - 1;
        digits[last]++;
        for (int i = last; i > 0; i--)
        {
            if (digits[i] == 10)
            {
                digits[i] = 0;
                digits[i - 1]++;
            }
        }

        if (digits[0] == 10)
        {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end

