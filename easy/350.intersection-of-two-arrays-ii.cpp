/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> table;
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++)
        {
            map<int,int>::iterator it = table.find(nums1[i]);
            if (it != table.end())
                it->second++;
            else
                table.insert(pair<int,int>(nums1[i], 1));
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            map<int,int>::iterator it = table.find(nums2[i]);
            if (it != table.end() && it->second != 0)
            {
                it->second--;
                result.push_back(nums2[i]);
            }
        }
        return result;
    }
};
// @lc code=end

