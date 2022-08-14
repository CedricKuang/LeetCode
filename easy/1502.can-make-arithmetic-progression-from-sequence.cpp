/*
 * @lc app=leetcode id=1502 lang=cpp
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if (arr[i] - arr[i - 1] != arr[i + 1] - arr[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

