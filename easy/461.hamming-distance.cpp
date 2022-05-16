/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
#include <cstdint>
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        uint32_t b_x = x;
        uint32_t b_y = y;
        uint32_t mask = 1;
        int result = 0;
        uint32_t re = b_x ^ b_y;

        for (int i = 0; i < 32; i++)
        {
            uint32_t temp = mask & re;
            if (temp == 1)
                result++;
            re = (re >> 1);
        }
        return result;
    }
};
// @lc code=end

