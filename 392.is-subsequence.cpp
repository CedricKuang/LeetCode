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
        int n = s.length(), m = t.length();
        int j = 0;
        for (int i = 0; i < m && j < n; i++)
        {
            if (s[j] == t[i])
                j++;
        }

        return (j == n);
    }
};
// @lc code=end

