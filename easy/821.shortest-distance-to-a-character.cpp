/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> occur;
        vector<int> result;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
                occur.push_back(i);
        }

        for (int i = 0; i < s.length(); i++)
        {
            int min = s.length();
            for (int m = 0; m < occur.size(); m++)
            {
                if (abs(i - occur[m]) < min)
                    min = abs(i - occur[m]);
            }
            result.push_back(min);
        }
        return result;
    }
};
// @lc code=end

