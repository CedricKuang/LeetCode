/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = 0;
        int curr = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            curr += gain[i];
            if (curr > max)
                max = curr;
        }
        return max;
    }
};
// @lc code=end

