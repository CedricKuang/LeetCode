/*
 * @lc app=leetcode id=1773 lang=cpp
 *
 * [1773] Count Items Matching a Rule
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        for (int i = 0; i < items.size(); i++)
        {
            if ((ruleKey == "type" && ruleValue == items[i][0]) || (ruleKey == "color" && ruleValue == items[i][1]) || (ruleKey == "name" && ruleValue == items[i][2]))
                ans++;
        }
        return ans;
    }
};
// @lc code=end

