/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> window;
        int left = 0, right = 0;
        vector<int> ans;
        while (right < nums.size())
        {
            window.push({nums[right], right});
            right++;

            if (right - left == k)
            {
                while (window.top().second < left)
                {
                    window.pop();
                }
                ans.push_back(window.top().first);
                left++;
            }
        }
        return ans;
    }
};
// @lc code=end

