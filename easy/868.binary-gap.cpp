/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int lastone = 32;
        int ans = 0;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i))
            {
                ans = max(ans,i-lastone);
                lastone = i;
            }
        }
        return ans;
    }
};
// @lc code=end

