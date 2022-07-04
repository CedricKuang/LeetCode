/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> wallet = {0, 0, 0};
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                wallet[0]++;
            else if (bills[i] == 10)
            {
                if (wallet[0] == 0)
                    return false;
                else
                {
                    wallet[0]--;
                    wallet[1]++;
                }
            }
            else
            {
                if (wallet[0] == 0)
                    return false;
                else if (wallet[1] == 0)
                {
                    if (wallet[0] >= 3)
                    {
                        wallet[0] -= 3;
                        wallet[2]++;
                    }
                    else
                        return false;
                }
                else
                {
                    wallet[0]--;
                    wallet[1]--;
                    wallet[2]++;
                }
            }
        }
        return true;
    }
};
// @lc code=end

