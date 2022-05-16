/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        if (s.empty())
            return 0;
        int word_count = 0;
        int num = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
                num++;
            else if (num != 0)
            {
                word_count++;
                num = 0;
            }
        }
        if (s[s.length() - 1] != ' ')
            word_count++;
        return word_count;
    }
};
// @lc code=end

