/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        map<int, char> special;
        int has_erase = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (!isalpha(s[i]))
            {
                special.insert(pair<int, char>(i + has_erase, s[i]));
                s.erase(i, 1);
                has_erase++;
                i--;
            }
        }

        reverse(s.begin(), s.end());
        for (map<int, char>::iterator it = special.begin(); it != special.end(); it++)
        {
            s.insert(it->first, 1, it->second);
        }
        return s;
    }
};
// @lc code=end

