/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_table;
        for (char c : s1)
            s1_table[c]++;
        
        int left = 0, right = 0, valid = 0;
        unordered_map<char, int> window;
        while (right < s2.length())
        {
            char c = s2[right];
            right++;
            if (s1_table.count(c) == 1)
            {
                window[c]++;
                if (window[c] == s1_table[c])
                    valid++;
            }

            while (right - left >= s1.length())
            {
                if (valid == s1_table.size())
                    return true;
                char d = s2[left];
                left++;
                if (s1_table.count(d) == 1)
                {
                    if (window[d] == s1_table[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;

    }
};
// @lc code=end

