/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        unordered_set<char> table;
        for (int i = 0; i < allowed.size(); i++)
            table.insert(allowed[i]);

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                if (table.count(words[i][j]) == 0)
                    break;
                if (j == words[i].size() - 1)
                    ans++;
            }
        }        
        return ans;
    }
};
// @lc code=end

