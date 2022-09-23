/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> my_queue;
        my_queue.push({sr, sc});
        int rows = image.size();
        int cols = image[0].size();
        while (!my_queue.empty())
        {
            int curr_row = my_queue.front().first;
            int curr_col = my_queue.front().second;
            my_queue.pop();
            if (image[curr_row][curr_col] == color)
                continue;
            if (curr_row > 0 && image[curr_row - 1][curr_col] == image[curr_row][curr_col])
                my_queue.push({curr_row - 1, curr_col});
            if (curr_row < rows - 1 && image[curr_row + 1][curr_col] == image[curr_row][curr_col])
                my_queue.push({curr_row + 1, curr_col});
            if (curr_col > 0 && image[curr_row][curr_col - 1] == image[curr_row][curr_col])
                my_queue.push({curr_row, curr_col - 1});
            if (curr_col < cols - 1 && image[curr_row][curr_col + 1] == image[curr_row][curr_col])
                my_queue.push({curr_row, curr_col + 1});
            image[curr_row][curr_col] = color;
        }
        return image;
    }
};
// @lc code=end

