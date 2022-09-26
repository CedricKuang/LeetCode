/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({nums2[i], i});
        }
        sort(nums1.begin(), nums1.end());

        int left = 0, right = n - 1;
        vector<int> result(n);

        while (!pq.empty())
        {
            int i = pq.top().second, maxval = pq.top().first;
            pq.pop();
            if (maxval < nums1[right])
            {
                result[i] = nums1[right];
                right--;
            }
            else
            {
                result[i] = nums1[left];
                left++;
            }
        }
        return result;

    }
};
// @lc code=end

