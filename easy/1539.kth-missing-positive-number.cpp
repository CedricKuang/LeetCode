/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> table;
        int miss = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            table.insert(arr[i]);
        }


        for (int i = 1;;i++)
        {
            if (table.count(i) == 0)
                miss++;
            
            if (miss == k)
                return i;
        }
        return -1;
    }
};
// @lc code=end

