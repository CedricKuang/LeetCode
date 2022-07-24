/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int summ = accumulate(arr.begin(), arr.end(), 0);
        int part = 0;
        int count = 0;
        if(summ % 3 == 0){
            
            for(int x : arr){
                
                part += x;
                
                if(part == (summ / 3)){
                    
                    count++;
                    part = 0;
                }
            }
        }
        return count >= 3;
    }
};
// @lc code=end

