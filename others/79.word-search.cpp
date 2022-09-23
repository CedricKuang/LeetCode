/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool DFS(vector<vector<char>>& board, vector<vector<int>>& path, string word, int index, int row, int col)
    {
        if (index == word.length())
            return true;
        int rows = board.size();
        int cols = board[0].size();
        if (row < 0 || row >= rows || col < 0 || col >= cols || path[row][col] == 1 || board[row][col] != word[index])
            return false;
        
        path[row][col] = 1;
        bool check = DFS(board, path, word, index + 1, row + 1, col) || DFS(board, path, word, index + 1, row - 1, col)
            || DFS(board, path, word, index + 1, row, col + 1) || DFS(board, path, word, index + 1, row, col - 1);
        path[row][col] = 0;
        return check;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                vector<vector<int>> path(board.size(), vector<int>(board[0].size()));
                if (board[i][j] ==  word[0] && DFS(board, path, word, 0, i, j))
                    return true;
            }
        }        
        return false;
    }
};
// @lc code=end

