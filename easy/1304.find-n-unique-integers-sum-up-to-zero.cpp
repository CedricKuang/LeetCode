/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for (int i = -1 * (n / 2); i < 0; i++)
            ans.push_back(i);
        if (n % 2 == 1)
            ans.push_back(0);
        for (int i = 1; i <= (n / 2); i++)
            ans.push_back(i);
        return ans;
    }
};
// @lc code=end

