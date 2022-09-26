/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0, right = 0;
        priority_queue<int> pq;
        unordered_map<int, int> window;
                                                                                                                                                                                                     
        vector<int> ans;
        while (right < nums.size())
        {
            window[nums[right]]++;
            pq.push(nums[right]);
            right++;

            if (right - left == k)
            {
                while (window[pq.top()] == 0)
                {
                    pq.pop();
                }
                ans.push_back(pq.top());
                window[nums[left]]--;
                left++;
            }
        }
        return ans;
    }
};
// @lc code=end

