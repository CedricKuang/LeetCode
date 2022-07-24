/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int n = 1;
        int i = 0;
        while (candies > 0)
        {
            if (candies < n)
                ans[i] += candies;
            else
                ans[i] += n;
            
            candies -= n;
            n++;
            i++;
            if (i >= num_people)
                i = 0;
        }
        return ans;
    }
};
// @lc code=end

