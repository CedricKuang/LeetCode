/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

// @lc code=start
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence);
        string word;
        int ans = 0;
        while (ss >> word)
        {
            ans++;
            auto res = std::mismatch(searchWord.begin(), searchWord.end(), word.begin());
            if (res.first == searchWord.end())
                return ans;
        }
        return -1;
    }
};
// @lc code=end

