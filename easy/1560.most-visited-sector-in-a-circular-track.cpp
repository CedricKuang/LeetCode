/*
 * @lc app=leetcode id=1560 lang=cpp
 *
 * [1560] Most Visited Sector in  a Circular Track
 */

// @lc code=start
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector <int> ans;
        int size = rounds.size();
        
        if(rounds[0] <= rounds[size-1]) {
            for(int i=rounds[0]; i<= rounds[size-1]; i++) {
                ans.push_back(i);
            }
            return ans;
        }
        else {
            for(int i=1; i<= rounds[size-1]; i++) {
                ans.push_back(i);
            }   
            
            for(int i=rounds[0]; i<=n; i++) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
// @lc code=end

