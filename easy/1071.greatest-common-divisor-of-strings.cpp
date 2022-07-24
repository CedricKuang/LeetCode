/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool is_divisor(string& str1, string& ans)
    {
        string temp = ans;
        while (temp.length() <= str1.length())
        {
            if (temp == str1)
                return true;
            temp += ans;
        }
        return false;
    }

    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        string real_ans = "";
        for (int i = 0; i < str1.length(); i++)
        {
            ans += str1[i];
            if (str1.length() % ans.length() == 0 && is_divisor(str1, ans) && is_divisor(str2, ans))
                real_ans = ans;
        }
        return real_ans;
    }
};
// @lc code=end

