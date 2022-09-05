/*
 * @lc app=leetcode id=1784 lang=cpp
 *
 * [1784] Check if Binary String Has at Most One Segment of Ones
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool curr_state = false;
        bool has_state = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                if (!curr_state && has_state)
                    return false;
                else
                {
                    curr_state = true;
                    has_state = true;
                }
            }
            else
                curr_state = false;
        }
        return true;
    }
};
// @lc code=end

