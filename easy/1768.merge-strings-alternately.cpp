/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        if (word1.length() >= word2.length())
        {
            int n = word2.length();
            int i = 0, j = 0;
            while (j < n)
            {
                if (i == j)
                {
                    ans += word1[i];
                    i++;
                }
                else
                {
                    ans += word2[j];
                    j++;
                }
            }

            while (i < word1.length())
            {
                ans += word1[i];
                i++;
            }
        }
        else
        {
            int n = word1.length();
            int i = 0, j = 0;
            while (i < n)
            {
                if (i == j)
                {
                    ans += word1[i];
                    i++;
                }
                else
                {
                    ans += word2[j];
                    j++;
                }
            }

            while (j < word2.length())
            {
                ans += word2[j];
                j++;
            }
        }
        return ans;
    }
};
// @lc code=end

