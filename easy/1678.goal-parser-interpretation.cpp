/*
 * @lc app=leetcode id=1678 lang=cpp
 *
 * [1678] Goal Parser Interpretation
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string ans = "";
        for (int i = 0; i < command.size();)
        {
            if (command[i] == '(')
            {
                if (command[i + 1] == 'a')
                {
                    ans += "al";
                    i += 4;
                }
                else
                {
                    ans += 'o';
                    i += 2;
                }
            }
            else if (command[i] == 'G')
            {
                ans += 'G';
                i++;
            }
            else
                i++;
        }
        return ans;
    }
};
// @lc code=end

