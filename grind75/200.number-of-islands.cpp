/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, -1));
        queue<pair<int, int>> my_queue;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == -1)
                {
                    ans++;
                    my_queue.push({i, j});
                    while (!my_queue.empty())
                    {
                        int curr_row = my_queue.front().first;
                        int curr_col = my_queue.front().second;
                        my_queue.pop();
                        if (visited[curr_row][curr_col] == 1 || grid[curr_row][curr_col] == '0')
                            continue;
                        visited[curr_row][curr_col] = 1;
                        if (curr_row > 0)
                            my_queue.push({curr_row - 1, curr_col});
                        if (curr_row < rows - 1)
                            my_queue.push({curr_row + 1, curr_col});
                        if (curr_col > 0)
                            my_queue.push({curr_row, curr_col - 1});
                        if (curr_col < cols - 1)
                            my_queue.push({curr_row, curr_col + 1});
                    }
                    
                }
            }
        }
        return ans;
    }
};
// @lc code=end

