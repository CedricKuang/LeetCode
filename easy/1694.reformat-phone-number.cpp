/*
 * @lc app=leetcode id=1694 lang=cpp
 *
 * [1694] Reformat Phone Number
 */

// @lc code=start
class Solution {
public:
    string reformatNumber(string number) {
        return regex_replace(regex_replace(number, regex("\\D"), ""), regex("...?(?=..)"), "$0-");
    }
};
// @lc code=end

