/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> table;
        unordered_set<string> id;
        string temp = "";
        int i, m;
        for (i = 0, m = 0; i < s.size() && m < pattern.size(); ++i)
        {
            if (s[i] != ' ' && i != s.size() - 1)
            {
                temp += s[i];
            }
            else
            {
                if (i == s.size() - 1)
                    temp += s[i];
                map<char, string>::iterator it = table.find(pattern[m]);
                if (it == table.end())
                {
                    table.insert(pair<char, string>(pattern[m], temp));
                    unordered_set<string>::iterator it2 = id.find(temp);
                    if (it2 == id.end())
                        id.insert(temp);
                    else
                        return false;
                }
                else
                {
                    if (it->second != temp)
                        return false;
                }
                temp = "";
                ++m;
            }
        }
        // cout << i << m << endl;
        if (i != s.size() || m != pattern.size())
             return false;
        return true;
    }
};
// @lc code=end

