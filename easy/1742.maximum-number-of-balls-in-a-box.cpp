/*
 * @lc app=leetcode id=1742 lang=cpp
 *
 * [1742] Maximum Number of Balls in a Box
 */

// @lc code=start
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> box (46,0);
        for(int i = lowLimit;i<=highLimit;i++)
        {
            int sum = 0;
            int temp = i;
            while(temp)
            {
                sum = sum + temp%10;
                temp = temp/10;
            }
            box[sum]++;
        }
        
        return *max_element(box.begin(),box.end());
    }
};
// @lc code=end

