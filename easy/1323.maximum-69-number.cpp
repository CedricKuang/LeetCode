/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string num_str = to_string(num);
        for (int i = 0; i < num_str.length(); i++)
        {
            if (num_str[i] == '6')
            {
                num_str[i] = '9';
                break;
            }
        }
        
        return stoi(num_str);
    }
};
// @lc code=end

