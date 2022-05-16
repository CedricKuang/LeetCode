/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int result = s.length();
        bool single_flag = false;
        map<char, int> table;
        for (int i = 0; i < s.length(); i++)
        {
            map<char,int>::iterator it = table.find(s[i]);
            if (it != table.end())
                it->second++;
            else 
                table.insert(pair<char,int>(s[i], 1));
        }
        if (table.size() == 1)
            return result;

        for (map<char,int>::iterator it = table.begin(); it != table.end(); it++)
        {
            if ((it->second % 2 != 0) && single_flag == false)
                single_flag = true;
            else if (it->second % 2 != 0)
                result--;
        }
        return result;
    }
};  
// @lc code=end

