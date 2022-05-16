/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // g for children , s for cookie
        int len_g = g.size();
        int len_s = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0,j = 0,ans = 0;
        while(i < len_g && j < len_s){
            if (s[j] >= g[i]){ // we alway want s[i] < g[j] , and if ( s[j] >= g[i] ) we get a answer,so we can get next element (cookie) by doing i++.
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
// @lc code=end
