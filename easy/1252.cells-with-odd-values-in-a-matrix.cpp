/*
 * @lc app=leetcode id=1252 lang=cpp
 *
 * [1252] Cells with Odd Values in a Matrix
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<bool> rows(n,false),cols(m,false);
        for(auto index: indices){
            rows[index[0]]=!rows[index[0]];
            cols[index[1]]=!cols[index[1]];
        }
        
        int oddCount(0);
        for(int i(0);i<n;i++){
            for(int j(0);j<m;j++){
                if(rows[i]^cols[j]) oddCount++;
            }
        }
        return oddCount;
    }
};
// @lc code=end

