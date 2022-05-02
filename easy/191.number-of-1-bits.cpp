/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
#include <stdint.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        int result = 0;
        for (int i = 0; i <= 31; i++)
        {
            int temp = n & mask;
            if (temp != 0)
                result++;
            mask = mask << 1;
        }
        return result;
    }
};
// @lc code=end

