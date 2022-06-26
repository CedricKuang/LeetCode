/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int number;
        unordered_map<int,pair<int,vector<int>>> hashmap;
        for(int i=0;i<nums.size();i++)
        {
            number  = nums[i];
            hashmap[number].first++;
            hashmap[number].second.push_back(i);
        }
        int degree = -1;
        for(auto it:hashmap)
        {
            if(it.second.first>degree){
                degree = it.second.first;
            }
        }
        
        int ans = nums.size();
            
        for(auto it:hashmap)
        {
            if(it.second.first==degree){
                int minimum = *min_element(it.second.second.begin(),it.second.second.end());
                int maximum = *max_element(it.second.second.begin(),it.second.second.end());
                
                if(maximum-minimum<ans){
                    ans = maximum - minimum;
                }
                
            }
        }
        
        return ans+1;
    }
};
// @lc code=end

