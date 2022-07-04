/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    map<string, int> get_all_words(string& s)
    {
        map<string, int> ans;
        string temp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
                temp += s[i];
            else
            {
                map<string, int>::iterator it = ans.find(temp);
                if (it != ans.end())
                    it->second++;
                else
                    ans.insert(pair<string, int>(temp, 1));
                temp = "";
            }
        }
        map<string, int>::iterator it = ans.find(temp);
        if (it != ans.end())
            it->second++;
        else
            ans.insert(pair<string, int>(temp, 1));
        return ans;
    }


    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> table1 = get_all_words(s1);
        map<string, int> table2 = get_all_words(s2);
        vector<string> ans;
        for (map<string, int>::iterator it = table1.begin(); it != table1.end(); it++)
        {
            if (it->second == 1)
            {
                map<string, int>::iterator temp_it = table2.find(it->first);
                if (temp_it == table2.end())
                    ans.push_back(it->first);
            }
        }

        for (map<string, int>::iterator it = table2.begin(); it != table2.end(); it++)
        {
            if (it->second == 1)
            {
                map<string, int>::iterator temp_it = table1.find(it->first);
                if (temp_it == table1.end())
                    ans.push_back(it->first);
            }
        }
        return ans;
    }
};
// @lc code=end

