/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        int start = 0, end = 0;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
                end++;
            else
            {
                if (end - start >= 2)
                {
                    vector<int> temp = {start, end};
                    result.push_back(temp);
                }
                start = i;
                end = i;
            }
        }
        if (end - start >= 2)
        {
            vector<int> temp = {start, end};
            result.push_back(temp);
        }
        return result;
    }
};
// @lc code=end

