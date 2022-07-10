/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        int r_i = 0, r_m = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int m = 0; m < board[0].size(); m++)
            {
                if (board[i][m] == 'R')
                {
                    r_i = i;
                    r_m = m;
                    break;
                }
            }
        }
        
        // right
        for (int m = (r_m + 1); m < board[0].size(); m++)
        {
            if (board[r_i][m] == 'p')
            {
                ans++;
                break;
            }
            if (board[r_i][m] == 'B')
                break;
        } 

        // left
        for (int m = (r_m - 1); m > -1; m--)
        {
            if (board[r_i][m] == 'p')
            {
                ans++;
                break;
            }
            if (board[r_i][m] == 'B')
                break;
        } 

        // down
        for (int i = (r_i + 1); i < board.size(); i++)
        {
            if (board[i][r_m] == 'p')
            {
                ans++;
                break;
            }
            if (board[i][r_m] == 'B')
                break;
        } 

        // up
        for (int i = (r_i - 1); i > -1; i--)
        {
            if (board[i][r_m] == 'p')
            {
                ans++;
                break;
            }
            if (board[i][r_m] == 'B')
                break;
        } 

        return ans;    
    }
};
// @lc code=end

