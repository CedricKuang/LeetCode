/*
 * @lc app=leetcode id=1816 lang=cpp
 *
 * [1816] Truncate Sentence
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int count =0;
        string ans="";
        for(auto x:s)
        {
            if(x==' ')
                count++;
            if(count==k)
                break;
            ans+=x;
        }
        
        return ans;
    }
};
// @lc code=end

