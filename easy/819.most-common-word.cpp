/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
#include <string>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    bool find_string (vector<string>& list, string target)
    {
        for (int i = 0; i < list.size(); i++)
            if (list[i] == target)
                return true;
        return false;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> table;
        string temp = "";
        for (int i = 0; i < paragraph.length(); i++)
        {
            if (!isalpha(paragraph[i]) && temp == "")
                continue;
            else if (isalpha(paragraph[i]))
            {
                temp += char(tolower(paragraph[i]));
            }
            else if (find_string(banned, temp))
            {
                temp = "";
                continue;
            }
            else
            {
                map<string, int>::iterator it = table.find(temp);
                if (it != table.end())
                    it->second++;
                else
                    table.insert(pair<string, int>(temp, 1));
                temp = "";
            }
        }
        if (temp != "")
        {
            map<string, int>::iterator it = table.find(temp);
            if (it != table.end())
                it->second++;
            else
                table.insert(pair<string, int>(temp, 1));
        }

        int max_index = 0;
        int max = 1;
        map<string, int>::iterator it = (table.begin());
        for (int i = 0; i < table.size(); i++, it++)
        {
            if (it->second > max)
            {
                max = it->second;
                max_index = i;
            }
        }
        it = (table.begin());
        for (int i = 0; i < max_index; i++)
            it++;
        return it->first;
    }
};
// @lc code=end

