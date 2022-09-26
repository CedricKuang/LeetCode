/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <vector>
using namespace std;


class Solution {
public:
    int f(vector<int>& piles, int x)
    {
        int days = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            days += piles[i] / x;
            if (piles[i] % x > 0)
                days++;
        }
        return days;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000 + 1;
        
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (f(piles, mid) <= h)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end

