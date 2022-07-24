/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        int rank = 1;
        unordered_map<int, int> table;
        for (int i = 0; i < sorted_arr.size(); i++)
        {
            if (table[sorted_arr[i]] == 0)
            {
                table[sorted_arr[i]] = rank;
                rank++;
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = table[arr[i]];
        }
        return arr;
    }
};
// @lc code=end

