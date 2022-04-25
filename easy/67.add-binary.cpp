/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int diff = a.length() - b.length();
        if (diff > 0)
        {
            for (int i = 0; i < diff; i++)
            {
                b.insert(b.begin(), '0');
            }
        }
        else
        {
            diff = -diff;
            for (int i = 0; i < diff; i++)
            {
                a.insert(a.begin(), '0');
            }
        }

        string result = "";
        int carry = 0;
        for (int i = a.length() - 1; i >= 0; i--)
        {
            int A = a[i] - '0';
            int B = b[i] - '0';
            int sum = carry ^ (A ^ B);
            carry = (A && B) || (B && carry) || (A && carry);
            char char_sum = sum + 48;
            result.insert(result.begin(), char_sum);
        }
        if (carry == 1)
            result.insert(result.begin(), '1');
        return result;

    }

};
// @lc code=end

