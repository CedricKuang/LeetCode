/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.length(); i++)
        {
            int m = i;
            for (int a = 0; a < needle.length(), m < haystack.length(); a++, m++)
            {
                if (haystack[m] != needle[a])
                    break;
                if (a == needle.length() - 1)
                    return i;
            }
        }       
        return -1; 
    }
};
// @lc code=end

