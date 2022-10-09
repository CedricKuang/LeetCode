/*
 * @lc app=leetcode id=1541 lang=cpp
 *
 * [1541] Minimum Insertions to Balance a Parentheses String
 */

// @lc code=start+
#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int res = 0, need = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                need += 2;
                if (need % 2 == 1)
                {
                    res++;
                    need--;
                }
            }
            if (s[i] == ')')
            {
                need--;
                if (need == -1)
                {
                    res++;
                    need = 1;
                }
            }
        }
        return res + need;
    }
};
// @lc code=end

