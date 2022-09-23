/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        int good = 0;
        int rotten = 0;
        queue<pair<int, int>> my_queue;
        vector<vector<int>> visited(rows, vector<int>(cols, -1));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    good++;
                    rotten++;
                    my_queue.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    good++;
                }
            }
        }

        if (rotten == good)
            return 0;
        else if (my_queue.empty())
            return -1;

        while (!my_queue.empty() && good > 0)
        {
            int sc = my_queue.size();
            for (int i = 0; i < sc; i++)
            {
                int curr_row = my_queue.front().first;
                int curr_col = my_queue.front().second;
                my_queue.pop();
                if (grid[curr_row][curr_col] == 0 || visited[curr_row][curr_col] == 1)
                {
                    continue;
                }
                    
                
                grid[curr_row][curr_col] = 2;
                visited[curr_row][curr_col] = 1;
                good--;
                
                if (curr_row > 0)
                    my_queue.push({curr_row - 1, curr_col});
                if (curr_row < rows - 1)
                    my_queue.push({curr_row + 1, curr_col});
                if (curr_col > 0)
                    my_queue.push({curr_row, curr_col - 1});
                if (curr_col < cols - 1)
                    my_queue.push({curr_row, curr_col + 1});
            }
            ans++;
        }

        if (good > 0)
            return -1;
        else
            return ans - 1;
    }
};
// @lc code=end

