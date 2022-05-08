/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
         map<char, int> table;
         for (int i = 0; i < s.length(); i++)
         {
            map<char, int>::iterator it = table.find(s[i]);
            if (it !=table.end())
                it->second++;
            else 
                table.insert(pair<char, int>(s[i], 1));
         }
         
         for (int i = 0; i < s.length(); i++)
         {
             map<char, int>::iterator it = table.find(s[i]);
             if (it->second == 1)
                return i;
         }
        

         return -1;
    }
};
// @lc code=end

