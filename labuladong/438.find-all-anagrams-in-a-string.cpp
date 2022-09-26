/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> p_table;
        for (char c : p)
            p_table[c]++;
        
        int left = 0, right = 0, valid = 0;
        vector<int> ans;
        unordered_map<char, int> window;
        while (right < s.length())
        {
            char c = s[right];
            right++;
            if (p_table.count(c))
            {
                window[c]++;
                if (window[c] == p_table[c])
                    valid++;
            }

            while (right - left >= p.length())
            {
                if (valid == p_table.size())
                    ans.push_back(left);
                char d = s[left];
                left++;
                if (p_table.count(d))
                {
                    if (window[d] == p_table[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

