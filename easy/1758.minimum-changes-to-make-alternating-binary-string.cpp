/*
 * @lc app=leetcode id=1758 lang=cpp
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int cnt1=0,cnt2=0;
        for(int i=0; i<s.size(); i++)
        {
            if(i%2==0)
            {
                if(s[i]=='1')
                    cnt1++;
                else
                    cnt2++;
            }
            else
            {
                if(s[i]=='0')
                    cnt1++;
                else
                    cnt2++;
            }
        }
        return min(cnt1,cnt2);
    }
};
// @lc code=end

