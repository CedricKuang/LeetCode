/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int total_one = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                total_one++;
        }
        int max = 0;
        int left_score = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '0')
                left_score++;
            else 
                total_one--;

            if (left_score + total_one > max)
                max = left_score + total_one;
        }
        return max;

    }
};
// @lc code=end

