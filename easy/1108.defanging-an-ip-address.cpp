/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        for (int i = 0; i < address.length(); i++)
        {
            if (address[i] == '.')
            {
                address.insert(i + 1, 1, ']');
                address.insert(i, 1, '[');
                i++;
            }
        }
        return address;
    }
};
// @lc code=end

