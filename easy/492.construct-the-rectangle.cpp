/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int m = sqrt(area);
        while (area % m != 0){
            m--;
        }
        return {area/m,m};
    }
};
// @lc code=end

