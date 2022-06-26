/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
 */

// @lc code=start
#include <string>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char, int> table;
        for (int i = 0; i < licensePlate.length(); i++)
        {
            if (!isalpha(licensePlate[i]))
                continue;
            map<char, int>::iterator it = table.find(tolower(licensePlate[i]));
            if (it != table.end())
                it->second++;
            else
                table.insert(pair<char,int>(tolower(licensePlate[i]), 1));
        }
        string ans = "";
        for (int i = 0; i < words.size(); i++)
        {
            map<char, int> temp_table = table;
            int m = 0;
            for (; m < words[i].length(); m++)
            {
                map<char, int>::iterator it = temp_table.find(words[i][m]);
                if (it == temp_table.end())
                    continue;
                else 
                    it->second--;
                if (it->second == 0)
                    temp_table.erase(it);
            }
            if (temp_table.empty())
            {
                if (ans == "")
                    ans = words[i];
                else if (ans.length() > words[i].length())
                    ans = words[i];
            }
                

        }
        return ans;

    }
};
// @lc code=end

