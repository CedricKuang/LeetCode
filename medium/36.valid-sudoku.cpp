/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> row(9), col(9), grid(9);
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                
                if (row[i].count(board[i][j]) || col[j].count(board[i][j]) || grid[3 * (i / 3) + j / 3].count(board[i][j]))
                {
                    return false;
                }
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                grid[3 * (i / 3) + j / 3].insert(board[i][j]);
            }
        }
        return true;
    }
};
// @lc code=end

