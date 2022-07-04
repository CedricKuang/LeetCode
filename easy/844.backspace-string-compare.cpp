/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#')
            {
                if (i == 0)
                {
                    s.erase(0, 1);
                    i--;
                }
                else
                {
                    s.erase(i - 1, 2);
                    i -= 2;
                }
            }
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == '#')
            {
                if (i == 0)
                {
                    t.erase(0, 1);
                    i--;
                }
                else
                {
                    t.erase(i - 1, 2);
                    i -= 2;
                }
            }
        }

        return (s == t);

    }
};
// @lc code=end

