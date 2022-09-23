/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> look_up_table;
        for (int i = 0; i < magazine.size(); i++)
            look_up_table[magazine[i]]++;
        for (int i = 0; i < ransomNote.size(); i++)
        {
            look_up_table[ransomNote[i]]--;
            if (look_up_table[ransomNote[i]] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

