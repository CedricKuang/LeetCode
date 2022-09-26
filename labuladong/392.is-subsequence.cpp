/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_pointer = 0, t_pointer = 0;
        while (s_pointer < s.length() && t_pointer < t.length())
        {
            if (s[s_pointer] == t[t_pointer])
            {
                s_pointer++;
            }
            t_pointer++;
        }
        return s_pointer == s.length();
    }
};
// @lc code=end

