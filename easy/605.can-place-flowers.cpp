/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int spot = 0;
        int consec = 1;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0)
                consec++;
            else 
            {
                spot += ((consec - 1) / 2);
                consec = 0;
            }
        }
        consec++;
        spot += ((consec - 1) / 2);
        return n <= spot;
    }
};
// @lc code=end

