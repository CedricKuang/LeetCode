/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> table;
        for (int i = 0; i < s.length(); i++)
            table[s[i]]++;
        for (int i = 0; i < t.length(); i++)
        {
            if (table[t[i]] == 0)
                return false;
            else
            {
                table[t[i]]--;
                if (table[t[i]] == 0)
                    table.erase(t[i]);
            }
        }
        return table.empty();
    }
};
// @lc code=end

