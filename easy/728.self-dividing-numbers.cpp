/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++)
        {
            int temp = i;
            while (temp > 0)
            {
                int digit = temp % 10;
                if (digit == 0 || i % digit != 0)
                    break;
                temp = temp / 10;
            }
            if (temp == 0)
                result.push_back(i);
        }
        return result;
    }
};
// @lc code=end

