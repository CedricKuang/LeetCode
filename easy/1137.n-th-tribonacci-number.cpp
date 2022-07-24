/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<int> trib(38, 0);
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
                trib[i] = 0;
            else if (i == 1)
                trib[i] = 1;
            else if (i == 2)
                trib[i] = 1;
            else
                trib[i] = trib[i -1] + trib[i - 2] + trib[i - 3];
        }
        return trib[n];
    }
};
// @lc code=end

