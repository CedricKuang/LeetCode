/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        for (int i = 0; i < s.length(); i++)
        {
            s = s + s[0];
            s.erase(s.begin());
            if (s == goal)
                return true;
        }
        return false;
    }
};
// @lc code=end

