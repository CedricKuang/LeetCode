/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length() == 1)
            return true;
        if (isupper(word[0]))
        {
            if (isupper(word[1]))
            {
                for (int i = 2; i < word.length(); i++)
                    if (!isupper(word[i]))
                        return false;
            }
            else
            {
                for (int i = 2; i < word.length(); i++)
                    if (!islower(word[i]))
                        return false;
            }
        }
        else 
        {
            for (int i = 1; i < word.length(); i++)
                if (!islower(word[i]))
                    return false;
        }
        return true;
    }
};
// @lc code=end

