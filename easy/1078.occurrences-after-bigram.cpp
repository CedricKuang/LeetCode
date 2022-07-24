/*
 * @lc app=leetcode id=1078 lang=cpp
 *
 * [1078] Occurrences After Bigram
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string temp = "";
        vector<string> sentence;
        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] != ' ')
                temp += text[i];
            else
            {
                sentence.push_back(temp);
                temp = "";
            }
        }
        sentence.push_back(temp);

        vector<string> ans;
        for (int i = 0; i < sentence.size() - 2; i++)
        {
            if (sentence[i] == first && sentence[i + 1] == second)
                ans.push_back(sentence[i + 2]);
        }
        return ans;
    }
};
// @lc code=end

