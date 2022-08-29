/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int nums_vowels_first = 0;
        int nums_vowels_second = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (vowels.count(s[i]) > 0)
            {
                if (i < s.length() / 2)
                    nums_vowels_first++;
                else
                    nums_vowels_second++;
            }
        }
        return nums_vowels_first == nums_vowels_second;
    }
};
// @lc code=end

