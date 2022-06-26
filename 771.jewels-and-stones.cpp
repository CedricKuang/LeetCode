/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> table;
        for (int i = 0; i < jewels.size(); i++)
        {
            table.insert(jewels[i]);
        }

        int result = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            unordered_set<char>::iterator it = table.find(stones[i]);
            if (it != table.end())
                result++;
        }
        return result;
    }
};
// @lc code=end

