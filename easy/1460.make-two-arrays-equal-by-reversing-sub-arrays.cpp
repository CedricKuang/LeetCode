/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Sub-arrays
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> table_arr;
        unordered_map<int, int> table_target;
        for (int i = 0; i < arr.size(); i++)
        {
            table_arr[arr[i]]++;
        }

        for (int i = 0; i < target.size(); i++)
        {
            table_target[target[i]]++;
        }

        for (int i = 0; i < target.size(); i++)
        {
            if (table_arr[target[i]] != table_target[target[i]])
                return false;
        }
        return true;
    }
};
// @lc code=end

