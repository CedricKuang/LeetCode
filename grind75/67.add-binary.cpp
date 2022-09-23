/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        while (a.length() < b.length())
            a = "0" + a;
        while (a.length() > b.length())
            b = "0" + b;
        
        string ans = "";
        string carry = "0";
        for (int i = a.length() - 1; i >= 0; i--)
        {
            if (a[i] == '0' && b[i] == '0')
            {
                ans = carry + ans;
                carry = "0";
            }
            else if (a[i] == '1' && b[i] == '1')
            {
                if (carry == "1")
                {
                    ans = carry + ans;
                }
                else
                {
                    ans = "0" + ans;
                    carry = "1";
                }
            }
            else
            {
                if (carry == "1")
                {
                    ans = "0" + ans;
                }
                else
                {
                    ans = "1" + ans;
                }
            }
        }
        ans = carry + ans;
        if (ans == "00")
            return "0";
        int pivot = 0;
        while (ans[pivot] == '0')
            pivot++;
        return ans.substr(pivot);
    }
};
// @lc code=end

