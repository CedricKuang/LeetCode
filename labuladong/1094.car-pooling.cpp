/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int, int> pick_up;
        unordered_map<int, int> drop_off;
        int dest = 0;
        for (int i = 0; i < trips.size(); i++)
        {
            pick_up[trips[i][1]] += trips[i][0];
            drop_off[trips[i][2]] += trips[i][0];
            dest = max(dest, trips[i][2]);
        }
        int curr = 0;
        for (int i = 0; i <= dest; i++)
        {
            curr -= drop_off[i];
            curr += pick_up[i];
            if (curr > capacity)
                return false;
        }
        return true;
    }
};
// @lc code=end

