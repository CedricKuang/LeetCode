/*
 * @lc app=leetcode id=806 lang=cpp
 *
 * [806] Number of Lines To Write String
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> result = {0, 0};
        for (int i = 0; i < s.length(); i++)
        {
            result[1] += widths[(s[i] - 97)];
            if (result[1] > 100)
            {
                result[0]++;
                result[1] = widths[(s[i] - 97)];
            }
        }
        result[0]++;
        return result;
    }
};
// @lc code=end

