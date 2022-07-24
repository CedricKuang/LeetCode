/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    double find_k(vector<int>& a, vector<int>& b)
    {
        if (a[0] == b[0])
            return 300;
        else
            return (double(a[1] - b[1]) / double(a[0] - b[0]));
    }

    bool is_distinct(vector<vector<int>>& points)
    {
        if ((points[0][0] == points[1][0] && points[0][1] == points[1][1]) ||
            (points[1][0] == points[2][0] && points[1][1] == points[2][1]) ||
            (points[0][0] == points[2][0] && points[0][1] == points[2][1]))
                return false;
        else
            return true;
    }

    bool isBoomerang(vector<vector<int>>& points) {
        if(!is_distinct(points))
            return false;
        double k1 = find_k(points[0], points[1]);
        double k2 = find_k(points[1], points[2]);
        double k3 = find_k(points[0], points[2]);
        // cout << k1 << " " << k2 << " " << k3 << endl;
        if (k1 == k2 || k2 == k3 || k3 == k1)
            return false;
        return true;
    }
};
// @lc code=end

