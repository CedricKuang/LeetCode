/*
 * @lc app=leetcode id=1844 lang=cpp
 *
 * [1844] Replace All Digits with Characters
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.length(); i += 2)
        {
            s[i] = (s[i - 1] + ((int)s[i] - 48));
        }
        return s;
    }
};
// @lc code=end

