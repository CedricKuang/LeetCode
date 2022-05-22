/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row_1 = "qwertyuiop";
        string row_2 = "asdfghjkl";
        string row_3 = "zxcvbnm";
        map<char, int> table;
        for (int i = 0; i < row_1.length(); i++)
            table.insert(pair<char, int>(row_1[i], 1));
        for (int i = 0; i < row_2.length(); i++)
            table.insert(pair<char, int>(row_2[i], 2));
        for (int i = 0; i < row_3.length(); i++)
            table.insert(pair<char, int>(row_3[i], 3));
        
        vector<string> result;
        for (int i = 0; i < words.size(); i++)
        {
            for (int m = 0; m < words[i].length(); m++)
            {
                if (m == words[i].length() - 1)
                {
                    result.push_back(words[i]);
                    break;
                }

                map<char, int>::iterator it1 = table.find(tolower(words[i][m]));
                map<char, int>::iterator it2 = table.find(tolower(words[i][m + 1]));
                if (it1->second != it2->second)
                    break;
            }
        }
        return result;
    }
};
// @lc code=end

