/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

// @lc code=start
#include <string>
using namespace std;


class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int num_l = 0;
        int num_r = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                num_l++;
            else if (s[i == 'R'])
                num_r++;
            
            if (num_l == num_r)
            {
                ans++;
                num_l = 0;
                num_r = 0;
            }
        }
        return ans;
    }
};
// @lc code=end

