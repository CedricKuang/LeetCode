/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());
        int min_diff = arr[1] - arr[0]; 
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i + 1] - arr[i] < min_diff)
                min_diff = arr[i + 1] - arr[i];
        }

        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i + 1] - arr[i] == min_diff)
                ans.push_back({arr[i], arr[i + 1]});
        }
        return ans;
    }
};
// @lc code=end

