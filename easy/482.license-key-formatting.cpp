/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int i = 0;
        while (i < s.length())
        {
            if (s[i] == '-')
                s.erase(i, 1);            
            else
            {
                s[i] = toupper(s[i]);
                i++;
            }
        }
        int initial = s.length() % k;
        if (initial == 0)
            initial = k;
        i = initial;
        while (i < s.length())
        {
            s.insert(i, 1, '-');
            i += (k + 1);
        } 
        return s;
    }
};
// @lc code=end

