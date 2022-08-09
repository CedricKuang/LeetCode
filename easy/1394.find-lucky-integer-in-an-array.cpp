/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> table;
        for (int i = 0; i < arr.size(); i++)
        {
            table[arr[i]]++;
        }

        int max = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == table[arr[i]] && arr[i] > max)
                max = arr[i];
        }
        return max;
    }
};
// @lc code=end

