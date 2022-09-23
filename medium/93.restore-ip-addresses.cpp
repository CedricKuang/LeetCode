/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // void helper(string s, vector<string>& ans, int count, int index)
    // {
    //     if ((count == 1 && (s.length() - index > 9 || s.length() - index < 3)) || (count == 2 && (s.length() - index > 6 || 
    //     s.length() - index < 2)) || (count == 3 && (s.length() - index > 3 || s.length() == index)))
    //         return;
    //     else if (count == 3 && (s[index] != '0' || index == s.length() - 1))
    //     {
    //         int tail = 0;
    //         int mul = 1;
    //         for (int i = s.length() - 1; i >= index; i--)
    //         {
    //             tail = ((int)s[i] - 48) * mul;
    //             mul *= 10;
    //         }
    //         if (tail >= 0 && tail <= 255)
    //             ans.push_back(s);
    //         return;
    //     }

    //     for (int i = index; i < index + 3 && i < s.length(); i++)
    //     {
    //         string temp_s = s;
    //         if (i == index)
    //         {
    //             temp_s.insert(i + 1, 1, '.');
    //             helper(temp_s, ans, count + 1, i + 2);
    //         }
    //         else if (i == index + 1)
    //         {
    //             if (s[i - 1] == '2' && s[i] <= '5')
    //             {
    //                 temp_s.insert(i + 1, 1, '.');
    //                 helper(temp_s, ans, count + 1, i + 2);
    //             }
    //             else if (s[i - 1] == '1')
    //             {
    //                 temp_s.insert(i + 1, 1, '.');
    //                 helper(temp_s, ans, count + 1, i + 2);
    //             }
    //             else
    //             {
    //                 temp_s.insert(i + 1, 1, '.');
    //                 helper(temp_s, ans, count + 1, i + 2);
    //                 break;
    //             }
    //         }
    //         else
    //         {
    //             if (s[i - 2] != '2' || s[i] <= '5')
    //             {
    //                 temp_s.insert(i + 1, 1, '.');
    //                 helper(temp_s, ans, count + 1, i + 2);
    //             }
    //         }
    //     }
    // }
    vector<string> restoreIpAddresses(string s) {
        std::vector<std::string> ret;
   
    for (int a = 1; a <= 3; ++a) {
      for (int b = 1; b <= 3; ++b) {
        for (int c = 1; c <= 3; ++c) {
          int d = s.size() - a - b - c;
          // Last number must use all remaining digits. Check;
          // 1. The size of the last number is valid
          // 2. Every number uses 1 digit for 0 and is less than 255 if using 3 digits
          if (1 <= d && d <= 3 && 
            (1 == a || '0' != s[0        ] && (3 != a || 0 < memcmp("256", &s[0        ], 3))) &&
            (1 == b || '0' != s[a        ] && (3 != b || 0 < memcmp("256", &s[a        ], 3))) &&
            (1 == c || '0' != s[a + b    ] && (3 != c || 0 < memcmp("256", &s[a + b    ], 3))) &&
            (1 == d || '0' != s[a + b + c] && (3 != d || 0 < memcmp("256", &s[a + b + c], 3)))) 
          {
            ret.emplace_back(s.substr(0, a) + "." + s.substr(a, b) + "." + s.substr(a + b, c) + "." + s.substr(a + b + c));
          }
        }
      }
    }
  
    return ret;
    }
};
// @lc code=end

