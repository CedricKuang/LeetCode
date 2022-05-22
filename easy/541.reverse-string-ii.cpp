/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2 * k)
        {
            if (i + k >= s.length())
                reverse(s.begin() + i, s.end());
            else 
                reverse(s.begin() + i, s.begin() + i + k);
        }
        return s;
    }
};
// @lc code=end

