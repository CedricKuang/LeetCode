/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size())
        {
            int a1 = firstList[i][0], a2 = firstList[i][1];
            int b1 = secondList[j][0], b2 = secondList[j][1];

            if (b2 >= a1 && a2 >= b1)
            {
                ans.push_back({max(a1, b1), min(a2, b2)});
            }
            if (b2 < a2)
                j++;
            else
                i++;
        }
        return ans;
    }
};
// @lc code=end

