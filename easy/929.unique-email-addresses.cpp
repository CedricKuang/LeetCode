/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> table;
        for (int i = 0; i < emails.size(); i++)
        {
            string temp = emails[i];
            int plus = -1, at_sign = -1;
            for (int i = 0; i < temp.length(); i++)
            {
                if (temp[i] == '.')
                {
                    temp.erase(i, 1);
                    i--;
                }
                if (temp[i] == '+' && plus == -1)
                    plus = i;
                else if (temp[i] == '@')
                {
                    at_sign = i;
                    break;
                }
            }

            if (plus != -1)
            {
                temp.erase(plus, at_sign - plus);
            }

            table.insert(temp);
        }
        return table.size();
    }
};
// @lc code=end

