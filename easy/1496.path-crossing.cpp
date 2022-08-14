/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */

// @lc code=start
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> table;
        int curr_x = 0;
        int curr_y = 0;
        table.insert({curr_x, curr_y});
        for (int i = 0; i < path.size(); i++)
        {
            switch (path[i])
            {
            case 'N':
                curr_y++;
                break;
            case 'W':
                curr_x--;
                break;
            case 'S':
                curr_y--;
                break;
            case 'E':
                curr_x++;
                break;
            default:
                break;
            }
            if (table.count({curr_x, curr_y}) > 0)
                return true;
            table.insert({curr_x, curr_y});
        }
        return false;
    }
};
// @lc code=end

