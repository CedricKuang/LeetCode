/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        for (int i = 0; i < (s.size() / 2); i++)
        {
            temp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = temp;
        }
    }
};
// @lc code=end

