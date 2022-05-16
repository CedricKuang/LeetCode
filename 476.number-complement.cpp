/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
#include <cstdint>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        uint32_t b_num = num;
        uint32_t b_num_dup = b_num;
        uint32_t mask = 1;
        int result = 0;
        while (b_num_dup > 0)
        {
            int temp = mask & b_num;
            if (temp == 0)
                result += mask;
            b_num_dup = b_num_dup >> 1;
            mask = mask << 1;
        } 
        return result;
        
    }
};
// @lc code=end

