/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] > max)
                max = candies[i];
        }
        vector<bool> ans;
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= max)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
// @lc code=end

