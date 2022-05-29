/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> set;
        string temp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                temp += ' ';
                set.push_back(temp);
                temp = "";
            }
            else
                temp = s[i] + temp;
        }
        set.push_back(temp);

        string ans = "";
        for (int i = 0; i < set.size(); i++)
        {
            ans += set[i];
        }
        return ans;
    }
};
// @lc code=end

