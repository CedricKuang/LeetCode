/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<char>>& grid, vector<vector<int>>& check, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        stack<pair<int, int>> my_stack;
        my_stack.push({i, j});
        while (!my_stack.empty())
        {
            int curr_i = my_stack.top().first;
            int curr_j = my_stack.top().second;
            my_stack.pop();
            if (curr_i < 0 || curr_i >= n || curr_j < 0 || curr_j >= m || check[curr_i][curr_j] == 1
            || grid[curr_i][curr_j] == '0')
                continue;
            check[curr_i][curr_j] = 1;
            my_stack.push({curr_i + 1, curr_j});
            my_stack.push({curr_i - 1, curr_j});
            my_stack.push({curr_i, curr_j - 1});
            my_stack.push({curr_i, curr_j + 1});
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> check(n, vector<int>(m));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && check[i][j] == 0)
                {
                    ans++;
                    DFS(grid, check, i, j);
                }
            }
        } 
        return ans;
    }
};
// @lc code=end

