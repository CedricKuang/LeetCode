/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool is_macth = false;
    unordered_set<string> dict;
    unordered_set<int> visited;

    void back_track(int index, string s)
    {
        if (is_macth)
            return;
        if (index == s.length())
        {
            is_macth = true;
            return;
        }
        string temp = "";
        for (int i = index; i < s.length(); i++)
        {
            temp += s[i];
            if (visited.count(i) == 0 && dict.count(temp) == 1)
            {
                visited.insert(i);
                back_track(i + 1, s);
            }
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++)
        {
            dict.insert(wordDict[i]);
        }
        back_track(0, s);
        return is_macth;
    }
};
// @lc code=end

