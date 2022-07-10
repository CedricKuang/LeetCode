/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty() && n==1)
            return 1;

        vector<int> trusted(n+1,0);
        vector<int> trusting(n+1,0);

        for (int i = 0; i < trust.size(); i++)
        {
            trusted[trust[i][1]]++;
            trusting[trust[i][0]]++;
        }

        for (int i = 0; i < trusted.size(); i++)
        {
            if (trusted[i] == (n - 1) && trusting[i] == 0)
                return i;
        }
        return -1;
    }
};
// @lc code=end

