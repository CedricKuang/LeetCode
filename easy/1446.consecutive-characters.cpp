/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int max_length = 1;
        int curr_length = 1;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                curr_length++;
            }
            else
            {
                curr_length = 1;
            }


            if (curr_length > max_length)
                max_length = curr_length;

        }
        return max_length;
    }
};
// @lc code=end

