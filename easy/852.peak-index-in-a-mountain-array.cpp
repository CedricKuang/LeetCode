/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i+1] < arr[i])
                return i;
        }
        return -1;
    }
};
// @lc code=end

