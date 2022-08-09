/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // complement of matrix 
        int n = matrix.size();
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; ++i) {
		// 2 Pointer approach :  just like we do in 1D array we take left and right pointers
		// and swap the values and then make those pointers intersect at some point.
            int left = 0, right = n-1;
            while(left < right) {
                swap(matrix[i][left], matrix[i][right]);
                ++left;
                --right;
            }
        }
    }
};
// @lc code=end

