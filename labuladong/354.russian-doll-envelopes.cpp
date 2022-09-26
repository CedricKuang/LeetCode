/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b)
    {
        if (a[0] == b[0])
            return b[1] < a[1];
        else
            return a[0] < b[0];
    }
    int lengthOfLIS(vector<int>& nums)
    {
        int piles = 0, n = nums.size();
        vector<int> top(n);
        for (int i = 0; i < n; i++)
        {
            int poker = nums[i];
            int left = 0, right = piles;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (top[mid] >= poker)
                    right = mid;
                else
                    left = mid + 1;
            }
            if (left == piles)
                piles++;
            top[left] = poker;
        }
        return piles;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> height(envelopes.size());
        for (int i = 0; i < envelopes.size(); i++)
            height[i] = envelopes[i][1];
        return lengthOfLIS(height);    
    }
};
// @lc code=end

