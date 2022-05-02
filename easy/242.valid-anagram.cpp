/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> table;
        for (int i = 0; i < s.length(); i++)
        {
            map<char,int>::iterator it = table.find(s[i]);
            if (it == table.end())
            {
                table[s[i]] = 1;
            }
            else 
                it->second++;
        }

        for (int i = 0; i < t.length(); i++)
        {
            map<char,int>::iterator it = table.find(t[i]);
            if (it == table.end())
                return false;
            else 
                it->second--;
            if (it->second == 0)
                table.erase(it);
        }

        return table.empty();
    }
};
// @lc code=end

