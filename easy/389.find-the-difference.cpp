/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> table;
        for (int i = 0; i < s.length(); i++)
        {
            map<char, int>::iterator it = table.find(s[i]);
            if (it != table.end())
                it->second++;
            else
                table.insert(pair<char, int>(s[i], 1));
        }

        for (int i = 0; i < t.length(); i++)
        {
            map<char, int>::iterator it = table.find(t[i]);
            if (it == table.end())
                return t[i];
            else 
            {
                it->second--;
                if (it->second == 0)
                    table.erase(it);
            }
        }
        
        return 'a';
    }
};
// @lc code=end

