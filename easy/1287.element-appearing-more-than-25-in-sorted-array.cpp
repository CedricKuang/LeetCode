/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> table;
        for (int i = 0; i < arr.size(); i++)
            table[arr[i]]++;
        
        for (unordered_map<int, int>::iterator it = table.begin(); it != table.end(); it++)
        {
            if (it->second > arr.size() / 4)
                return it->first;
        }
        return -1;
    }
};
// @lc code=end

