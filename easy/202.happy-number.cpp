/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
using namespace std;
int timer = 0;

class Solution {
public:
    int digitSqSum(int n){
        int sum=0;
        while(n>0){
            sum=sum+((n%10)*(n%10));
            n=n/10;
        }
        return sum;
    }
    
    bool isHappy(int n) {        
        int temp=n;
        while(1)
        {
            if(temp==89)
                return false;
            if(temp==1)
                return true;
            temp=digitSqSum(temp);
        }
    }
};
// @lc code=end

