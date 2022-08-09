/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
bool compare(string &s1,string &s2)
{
    return s1.size() < s2.size();
}

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        vector<string> ans;
        for (int i = 0; i < words.size() - 1; i++)
        {
            for (int m = i + 1; m < words.size(); m++)
            {
                if (words[m].find(words[i]) != string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

