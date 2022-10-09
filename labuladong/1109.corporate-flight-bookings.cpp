/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 */

// @lc code=start
#include <vector>
using namespace std;

class Difference
{
    private:
        vector<int> diff;
    public:
        Difference(vector<int>& nums)
        {
            diff.push_back(nums[0]);
            for (int i = 1; i < nums.size(); i++)
            {
                diff.push_back(nums[i] - nums[i - 1]);
            }
        }
        void increment(int i, int j, int val)
        {
            diff[i] += val;
            if (j + 1 < diff.size())
                diff[j + 1] -= val;
        }
        vector<int> result()
        {
            vector<int> result(diff.size());
            result[0] = diff[0];
            for (int i = 1; i < diff.size(); i++)
            {
                result[i] = result[i - 1] + diff[i];
            }
            return result;
        }
};


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        Difference df{ans};

        for (vector<int> booking : bookings)
        {
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int val = booking[2];
            df.increment(i, j, val);
        }

        return df.result();

    }
};
// @lc code=end

