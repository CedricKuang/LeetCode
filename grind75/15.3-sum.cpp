/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if(nums.size() < 3){    
            return {};
        }
        if(nums[0] > 0){        
            return {};
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high)
            {
                if (nums[low] + nums[high] + nums[i] == 0)
                {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    int curr_low = nums[low];
                    int curr_high = nums[high];
                    while (low < high&& nums[low] == curr_low)
                        low++;
                    while (high > low && nums[high] == curr_high)
                        high--;       
                }
                else if ((nums[low] + nums[high] + nums[i] > 0))
                    high--;
                else
                    low++;
            }
        }   
        return ans;   

    }
};
// @lc code=end

