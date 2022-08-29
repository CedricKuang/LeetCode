/*
 * @lc app=leetcode id=1725 lang=cpp
 *
 * [1725] Number Of Rectangles That Can Form The Largest Square
 */

// @lc code=start
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int, int> table;
        for (int i = 0; i < rectangles.size(); i++)
        {
            if (rectangles[i][0] < rectangles[i][1])
                table[rectangles[i][0]]++;
            else
                table[rectangles[i][1]]++;
        }

        return table.rbegin()->second;
    }
};
// @lc code=end

