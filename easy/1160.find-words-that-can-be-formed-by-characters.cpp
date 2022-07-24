/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */

// @lc code=start
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> table;
        for (int i = 0; i < chars.length(); i++)
            table[chars[i]]++;
        
        int ans = 0;
        for (int i = 0; i < words.size(); i++)
        {
            unordered_map<char, int> temp_table = table;
            int m = 0;
            for (; m < words[i].length(); m++)
            {
                if (temp_table[words[i][m]] == 0)
                    break;
                else 
                    temp_table[words[i][m]]--;
            }
            if (m == words[i].length())
                ans += words[i].length();
        }
        return ans;
    }
};
// @lc code=end

