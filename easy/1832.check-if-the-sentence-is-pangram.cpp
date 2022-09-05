/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> table;
        for (int i = 0; i < sentence.length(); i++)
        {
            table.insert(sentence[i]);
        }
        return table.size() == 26;
    }
};
// @lc code=end

