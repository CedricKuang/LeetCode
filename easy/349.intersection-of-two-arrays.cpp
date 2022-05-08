/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> table;
        for (int i = 0; i < nums1.size(); i++)
        {
            table.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            unordered_set<int>::iterator it = table.find(nums2[i]);
            if (it != table.end())
            {
                result.push_back(*it);
                table.erase(it);
            }
        }
        return result;
    }
};
// @lc code=end

