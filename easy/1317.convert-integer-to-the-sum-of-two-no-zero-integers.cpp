/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool checkZero(int n)
    {
        while (n > 0)
        {
            if (n % 10 == 0)
                return true;
            n = n / 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        int LSB = n % 10;
        int others = n - LSB;

        if (others == 0)
        {
            others++;
            LSB--;
        }        

        while (checkZero(others) || checkZero(LSB))
        {
            others--;
            LSB++;
        }

        ans.push_back(LSB);
        ans.push_back(others);
        return ans;
    }
};
// @lc code=end

