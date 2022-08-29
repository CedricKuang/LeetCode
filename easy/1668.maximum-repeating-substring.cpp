/*
 * @lc app=leetcode id=1668 lang=cpp
 *
 * [1668] Maximum Repeating Substring
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if (sequence.length() < word.length())
            return 0;
        int ans = 0;
        int max = 0;
        for (int i = 0; i < sequence.size() - word.size() + 1;)
        {
            string sub = sequence.substr(i, word.size());
            if (sub == word)
            {
                ans++;
                i = i + word.size();
            }
            else
            {
                if (ans != 0)
                {
                    ans = 0;
                    i -= (word.size() - 1);
                }
                else 
                    i++;
            }
            if (ans > max)
                max = ans;
        }
        return max;
    }
};
// @lc code=end

