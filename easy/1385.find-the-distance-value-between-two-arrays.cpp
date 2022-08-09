/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            int m = 0;
            for (; m < arr2.size(); m++)
            {
                if (abs(arr1[i] - arr2[m]) <= d)
                    break;
            }
            if (m == arr2.size())
                ans++;
        }
        return ans;
    }
};
// @lc code=end

