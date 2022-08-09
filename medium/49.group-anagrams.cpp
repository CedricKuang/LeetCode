/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        for (int i = 0; i < strs.size(); i++)
        {
            string sorted_str = strs[i];
            sort(sorted_str.begin(), sorted_str.end());
            table[sorted_str].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (unordered_map<string, vector<string>>::iterator it = table.begin(); it != table.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};
// @lc code=end

