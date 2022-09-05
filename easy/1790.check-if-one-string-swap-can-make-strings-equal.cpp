/*
 * @lc app=leetcode id=1790 lang=cpp
 *
 * [1790] Check if One String Swap Can Make Strings Equal
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;
        unordered_map<char, int> table;
        for (int i = 0; i < s1.length(); i++)
            table[s1[i]]++;
        for (int i = 0; i < s2.length(); i++)
        {
            if (table[s2[i]] == 0)
                return false;
            else
                table[s2[i]]--;
        }
        int diff = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                diff++;
        }
        return diff == 2;
    }
};
// @lc code=end

