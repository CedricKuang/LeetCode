/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (int i = 0; i < columnTitle.length(); i++)
        {
            result = result + (int)(columnTitle[columnTitle.length() - i - 1] - '@') * pow(26, i);
        }
        return result;
    }
};
// @lc code=end

