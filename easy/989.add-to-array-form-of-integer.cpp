/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        for(int i=A.size()-1;i>=0&&K>0;i--)
        {
            A[i]+=K;
            K=A[i]/10;
            A[i]%=10;
        }
        while(K>0)
        {
            A.insert(A.begin(),K%10);
            K/=10;
        }
        return A;
    }
};
// @lc code=end

