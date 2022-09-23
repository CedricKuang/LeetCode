/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        int score[n];
        priority_queue<pair<int, int>> pq;
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(pq.size() && pq.top().second>i+k)
                pq.pop();
            
            score[i]=nums[i];
            score[i]+=(pq.size() ? pq.top().first : 0);
            pq.push({score[i], i});
        }
        
        return score[0];
    }
};
// @lc code=end

