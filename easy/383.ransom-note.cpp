/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> table;
        for (int i = 0; i < magazine.length(); i++)
        {
            map<char,int>::iterator it = table.find(magazine[i]);
            if (it != table.end())
                it->second++;
            else
                table.insert(pair<char, int>(magazine[i], 1));
        }

        for (int i = 0; i < ransomNote.length(); i++)
        {
            map<char,int>::iterator it = table.find(ransomNote[i]);
            if (it == table.end())
                return false;
            else 
            {
                it->second--;
                if (it->second == 0)
                    table.erase(it);
            }
        }

        return true;
    }
};
// @lc code=end

