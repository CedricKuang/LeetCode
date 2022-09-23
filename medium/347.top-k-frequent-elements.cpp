/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <unordered_map>
#include <map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto num : nums) freq[num]++;
        
        priority_queue<pair<int, int>> pq;
        for (auto [a, b] : freq) pq.push({b, a});
        
        vector<int> res;
        while (k) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return res;
    }
};
// @lc code=end

