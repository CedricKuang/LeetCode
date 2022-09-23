/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> table;
        vector<int> r_table;
        for (int i = 0; i < s.length(); i++)
            table[s[i]]++;
        for (auto it = table.begin(); it != table.end(); it++)
            r_table.push_back(it->second);
        int ans = 0;
        bool is_odd = false;
        sort(r_table.begin(), r_table.end());
        for (int i = r_table.size() - 1; i >= 0; i--)
        {
            if (r_table[i] % 2 == 0)
                ans += r_table[i];
            else if (!is_odd)
            {
                ans += r_table[i];
                is_odd = true;
            }
            else
            {
                ans += (r_table[i] - 1);
            }
        }
        return ans;
    }
};
// @lc code=end

