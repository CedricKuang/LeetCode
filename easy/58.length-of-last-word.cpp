/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = -1;
        int count = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == ' ' && isalpha(s[i+1]))
            {
                pos = i;
            }
        }

        for (int i = pos + 1; i < s.length(); i++)
        {
            if (!isalpha(s[i]))
                break;
            count++;
        }
        return count;
    }
};
// @lc code=end

