/*
 * @lc app=leetcode id=1030 lang=cpp
 *
 * [1030] Matrix Cells in Distance Order
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // time limit exceeded
    // int get_distance(vector<int>& point, int x, int y)
    // {
    //     return (abs(point[0] - x) + abs(point[1] - y));
    // }
    // vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    //     vector<vector<int>> ans;
    //     for (int i = 0; i < rows; i++)
    //     {
    //         for (int m = 0; m < cols; m++)
    //         {
    //             ans.push_back({i, m});
    //         }
    //     }
        
    //     for (int i = 0; i < ans.size() - 1; i++)
    //     {
    //         for (int m = 0; m < ans.size() - 1 - i; m++)
    //         {
    //             if (get_distance(ans[m], rCenter, cCenter) > get_distance(ans[m + 1], rCenter, cCenter))
    //                 swap(ans[m], ans[m + 1]);
    //         }
    //     }
    //     return ans;
    // }

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ans.push_back({i, j, abs(i - r0) + abs(j - c0)});

        sort(ans.begin(), ans.end(), [](vector<int>& c1, vector<int>& c2) {
            return c1[2] < c2[2];
        });

        for (vector<int>& d: ans) 
            d.pop_back();

        return ans;
    }
};
// @lc code=end

