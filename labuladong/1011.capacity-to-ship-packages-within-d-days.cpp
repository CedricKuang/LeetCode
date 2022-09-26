/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int f(vector<int>& weights, int x)
    {
        int days = 0;
        for (int i = 0; i < weights.size();)
        {
            int cap = x;
            while (i < weights.size())
            {
                if (cap < weights[i])
                    break;
                else
                    cap -= weights[i];
                i++;
            }
            days++;
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 1;
        for (int w : weights)
        {
            left = max(left, w);
            right += w;
        }

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (f(weights, mid) <= days)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end

