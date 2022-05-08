/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        char temp;
        for (int i = 0, m = s.size() - 1; i < m;)
        {
            if (isVowels(s[i]))
            {
                if (isVowels(s[m]))
                {
                    temp = s[i];
                    s[i] = s[m];
                    s[m] = temp;
                    i++;
                    m--;
                }
                else
                    m--;
            }
            else if (isVowels(s[m]))
            {
                if (isVowels(s[i]))
                {
                    temp = s[i];
                    s[i] = s[m];
                    s[m] = temp;
                    i++;
                    m--;
                }
                else
                    i++;
            }
            else
            {
                i++;
                m--;
            }
        }
        return s;
    }

    bool isVowels(char s)
    {
        s = tolower(s);
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
            return true;
        else 
            return false;
    }
};
// @lc code=end

