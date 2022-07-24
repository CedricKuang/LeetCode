/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        else if (s.length() == 1)
            return 1;
        
        int back = 0;
        int front = 1;
        int max_length = 0;
        unordered_map<char, int> table;
        table[s[0]] = 0;
        while (front != s.length())
        {
            unordered_map<char, int>::iterator it = table.find(s[front]);
            if (it == table.end() || it->second < back)
            {
                table[s[front]] = front;
            }
            else
            {
                back = table[s[front]] + 1;
                table[s[front]] = front;
            }
            if (front - back + 1 > max_length)
                max_length = front - back + 1;
            // cout << back << " " << front << " " << max_length << endl;
            front++;
        }
        return max_length;
    }
};
// @lc code=end

