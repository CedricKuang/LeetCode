/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> moses = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) {
        map<string, int> table;
        for (int i = 0; i < words.size(); i++)
        {
            string temp = "";
            for (int m = 0; m < words[i].length(); m++)
            {
                temp += moses[words[i][m] - 97];
            }
            map<string, int>::iterator it = table.find(temp);
            if (it != table.end())
                it->second++;
            else
                table.insert(pair<string, int>(temp, 1));
        }
        return table.size();
    }
};
// @lc code=end

