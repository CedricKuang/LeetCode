/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <vector>
#include <stack>
#include <string>
using namespace std;



class Solution {
public:
    bool DFS(vector<vector<char>>& board, int row, int col, int index, string word)
    {
        if (index == word.length())
            return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || word[index] != board[row][col])
            return false;
        
        board[row][col] = '0';
        bool status = DFS(board, row - 1, col, index + 1, word) || DFS(board, row + 1, col, 
        index + 1, word) || DFS(board, row, col - 1, index + 1, word) || DFS(board, row, col + 1, index + 1, word);
        board[row][col] = word[index];
        return status;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (word[0] == board[i][j] && DFS(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

