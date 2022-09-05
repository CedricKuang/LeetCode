/*
 * @lc app=leetcode id=1736 lang=cpp
 *
 * [1736] Latest Time by Replacing Hidden Digits
 */

// @lc code=start
#include <string>
using namespace std;


class Solution {
public:
    string maximumTime(string time) {
        for (int i = 0; i < time.length(); i++)
        {
            if (time[i] == '?')
            {
                if (i == 0)
                {
                    if (time[1] > 51 && time[1] != '?')
                        time[0] = '1';
                    else
                        time[0] = '2';
                }

                else if (i == 1)
                {
                    if (time[0] == '2')
                        time[1] = '3';
                    else
                        time[1] = '9';
                }

                else if (i == 3)
                {
                    time[3] = '5';
                }

                else
                {
                    time[4] = '9';
                }
            }
        }
        return time;        
    }
};
// @lc code=end

