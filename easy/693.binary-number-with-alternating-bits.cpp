/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> bits;
        while (n > 0) {
            bits.push_back(n % 2);
            n = n / 2;
        }

        for (int i = 0; i < bits.size() - 1; i++)
        {
            if (bits[i] + bits[i + 1] != 1)
                return false;
        }
        return true;
    }
};
// @lc code=end

