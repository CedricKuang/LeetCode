/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
#include <vector>
using namespace std;


class Solution {
public:
    static bool comparator(vector<int>& v1, vector<int>& v2)
    {
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comparator);
        int ans = 0;
        for (int i = 0; i < boxTypes.size(); i++)
        {
            if (boxTypes[i][0] <= truckSize)
            {
                ans += (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            }     
            else
            {
                ans += ((truckSize) * boxTypes[i][1]);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

