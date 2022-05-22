/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        string result = "";
        int dup_num = num;
        while (num != 0)
        {
            result = (char)(abs(num % 7) + 48) + result;
            num = num / 7; 
        }
        if (dup_num < 0)
            result = '-' + result;
        return result;
    }
};
// @lc code=end

