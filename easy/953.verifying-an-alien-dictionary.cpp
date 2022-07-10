/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool compare_order(string& s1, string& s2, map<char,int>& order)
    {
        int i = 0, j = 0;
        while (i != s1.length() && j != s2.length())
        {
            map<char, int>::iterator it1 = order.find(s1[i]);
            map<char, int>::iterator it2 = order.find(s2[j]);
            if (it1->second < it2->second)
                return true;
            else if (it1->second > it2->second)
                return false;
            i++;
            j++;
        }
        if (s1.length() <= s2.length())
            return true;
        else
            return false;

    }

    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> table;
        for (int i = 0; i < order.length(); i++)
            table.insert(pair<char, int>(order[i], i));
        
        for (int i = 0; i < words.size() - 1; i++)
        {
            if (!compare_order(words[i], words[i + 1], table))
                return false;    
        }        
        return true;
    }
};
// @lc code=end

