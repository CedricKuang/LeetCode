/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */

// @lc code=start
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        unordered_map<int, char> table;
        for (int i = 0; i < indices.size(); i++)
        {
            table[indices[i]] = s[i]; 
        }

        for (int i = 0; i < indices.size(); i++)
        {
            s[i] = table[i];
        }
        return s;
    }
};
// @lc code=end

