/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int even=0,odd=0;
        for(int i=0;i<chips.size();i++){
            if(chips[i]%2==0)
                even++;
            else
                odd++;
        }
        if(even>odd)
            return odd;
        return even;
    }
};
// @lc code=end

