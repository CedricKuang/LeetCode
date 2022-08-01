/*
 * @lc app=leetcode id=1374 lang=cpp
 *
 * [1374] Generate a String With Characters That Have Odd Counts
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string generateTheString(int n) {
        if (n == 1)
            return "a";
        vector<int> nums(3,0);
        nums[0] = n / 2;
        nums[1] = n - (n / 2);
        if (nums[0] % 2 == 0 && nums[1] % 2 == 0)
        {
            nums[0]++;
            nums[1]--;
        }
        else if (nums[0] % 2 == 1 && nums[1] % 2 == 0)
        {
            nums[1]--;
            nums[2]++;
        }
        else if (nums[0] % 2 == 0 && nums[1] % 2 == 1)
        {
            nums[0]--;
            nums[2]++;
        }

        string ans = "";
        for (int i = 0; i < 3; i++)
        {
            for (int m = 1; m <= nums[i]; m++)
            {
                if (i == 0)
                    ans += "a";
                else if (i == 1)
                    ans += "b";
                else 
                    ans += "c";
            }
        }
        return ans;
    }
};
// @lc code=end

