/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> table;
        for (int i = 0; i < arr.size(); i++)
            table[arr[i]]++;
        unordered_map<int, int>::iterator it1 = table.begin();
        while (it1 != table.end())
        {
            unordered_map<int, int>::iterator it2 = it1;
            it2++;
            while (it2 != table.end())
            {
                if (it1->second == it2->second)
                    return false;
                it2++;
            }
            it1++;
        }
        return true;
    }
};
// @lc code=end

