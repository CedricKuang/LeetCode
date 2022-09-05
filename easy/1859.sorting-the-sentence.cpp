/*
 * @lc app=leetcode id=1859 lang=cpp
 *
 * [1859] Sorting the Sentence
 */

// @lc code=start
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        int nums = 0;
        string word;
        unordered_map<int, string> table;
        while (ss >> word)
        {   
            table[stoi(word.substr(word.size() - 1))] = word.substr(0, word.size() - 1);
            nums++;
        }
        string ans = "";
        for (int i = 1; i <= nums; i++)
        {
            if (i != nums)
                ans += (table[i] + " ");
            else
                ans += table[i];
        }
            
        
        return ans;
    }
};
// @lc code=end

