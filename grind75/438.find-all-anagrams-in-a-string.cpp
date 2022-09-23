/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length())
            return {};
        unordered_map<char, int> need, window;
        for (int i = 0; i < p.size(); i++)
        {
            need[p[i]]++;
        }

        int left = 0, right = 0, valid = 0;
        vector<int> res;

        while (right < s.size())
        {
            char c = s[right];
            right++;

            if (need.count(c))
            {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            while (right - left >= p.size())
            {
                if (valid == need.size())
                    res.push_back(left);
                char d = s[left];
                left++;
                if (need.count(d))
                {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

