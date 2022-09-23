/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, string> digit_to_char = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

class Solution {
public:
    vector<string> ans;
    void back_track(string temp, int index, string& digits)
    {
        if (index == digits.size())
        {
            ans.push_back(temp);
        }
        for (int i = 0; i < digit_to_char[digits[index]].length(); i++)
        {
            back_track(temp + digit_to_char[digits[index]][i], index + 1, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return ans;
        back_track("", 0, digits);
        return ans;
    }
};
// @lc code=end

