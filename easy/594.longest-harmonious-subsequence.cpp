/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto n : nums)
            freq[n]++;
        
        int maxi = 0;
        for (auto [num, f] : freq) {
            if (freq.find(num+1) != freq.end())
                maxi = max(maxi, f + freq[num+1]);
        }
        return maxi;
    }
};
// @lc code=end

