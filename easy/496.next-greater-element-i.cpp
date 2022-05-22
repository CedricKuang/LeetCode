/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++)
        {   int target = -1;
            for (int m = 0; m < nums2.size(); m++)
            {
                if (nums1[i] == nums2[m])
                    target = nums1[i];
                else if (target != -1 && nums2[m] > target)
                {
                    result.push_back(nums2[m]);
                    break;
                }
                if (m == nums2.size() - 1)
                    result.push_back(-1);
            }
        }       
        return result;
    }
};
// @lc code=end

