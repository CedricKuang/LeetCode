/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_table;
        for (char c : t)
            t_table[c]++;
        
        int left = 0, right = 0, valid = 0, min_length = INT_MAX, min_left = -1, min_right = -1;
        string ans = "";
        unordered_map<char, int> window;
        while (right < s.length())
        {
            char c = s[right];
            right++;

            if (t_table.count(c) == 1)
            {
                window[c]++;
                if (window[c] == t_table[c])
                    valid++;
            }

            while (valid == t_table.size())
            {
                if (right - left < min_length)
                {
                    min_length = right - left + 1;
                    min_left = left;
                    min_right = right - 1;
                }
                char d = s[left];
                left++;
                if (t_table.count(d) == 1)
                {
                    if (window[d] == t_table[d])
                        valid--;
                    window[d]--;
                }
            }
        }

        if (min_left != -1 && min_right != -1)
        {
            for (int i = min_left; i <= min_right; i++)
                ans += s[i];
        }

        return ans;
    }
};
// @lc code=end

