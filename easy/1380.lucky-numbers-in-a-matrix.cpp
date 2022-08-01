/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int small, big;
        vector<int> vect;
        for(int itr = 0; itr < matrix.size(); itr++){
        int ktr = 0;
        small = 999999;             
        for(int jtr = 0; jtr < matrix[0].size(); jtr++){                
            if(small > matrix[itr][jtr]){
                small = matrix[itr][jtr];
                ktr = jtr;
            }
        }
        big = small;
        for(int jtr = 0; jtr < matrix.size(); jtr++){
            big = max(big, matrix[jtr][ktr]);
        }
        if(small == big) {
            vect.push_back(small);
        }
    }
    return vect;
    }
};
// @lc code=end

