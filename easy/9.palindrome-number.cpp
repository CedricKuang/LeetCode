/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        int mod = 10;
        vector<int> all_mods;
        while (x > 0) {
            int a = x % mod;
            all_mods.push_back(a);
            x = x/10;
        }
        if (all_mods.size() == 1)
            return true;
        vector<int>::iterator it1 = all_mods.begin();
        vector<int>::iterator it2 = all_mods.end();
        // for (; it1 != all_mods.end(); it1++)
        //     cout << *it1;
        // it1 = all_mods.begin();
        it2--;
        int half_mod_size = all_mods.size() / 2;
        for (int i = 1; i <= half_mod_size; i++, it1++, it2--)
        {
            if (*it1 != *it2)
                return false;
        }
        return true;
    }
};
// @lc code=end

