/*
 * @lc app=leetcode id=1556 lang=cpp
 *
 * [1556] Thousand Separator
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        string s_n = to_string(n);
        int count = 0;
        for (int i = s_n.size() - 1; i >= 0; i--)
        {
            count++;
            if (count == 3 && i != 0)
            {
                s_n.insert(i, 1,'.');
                count = 0;
            }
        }
        return s_n;
    }
};
// @lc code=end

