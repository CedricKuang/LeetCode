/*
 * @lc app=leetcode id=1576 lang=cpp
 *
 * [1576] Replace All ?'s to Avoid Consecutive Repeating Characters
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '?')
            {
                if (i == 0)
                {
                    if (s[1] == 'a')
                        s[0] = 'b';
                    else
                        s[0] = 'a';
                }
                else if (i == s.size() - 1)
                {
                    if (s[s.size() - 2] == 'a')
                        s[s.size() - 1] = 'b';
                    else
                        s[s.size() - 1] = 'a';
                }
                else
                {
                    if ((s[i - 1] == 'a' && s[i + 1] == 'b') || (s[i - 1] == 'b' && s[i + 1] == 'a'))
                        s[i] = 'c';
                    else if (s[i - 1] == 'a' || s[i + 1] == 'a')
                        s[i] = 'b';
                    else
                        s[i] = 'a'; 
                }
            }
        }
        return s;
    }
};
// @lc code=end

