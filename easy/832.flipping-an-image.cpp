/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i = 0; i < image.size(); i++)
        {
            for (int m = 0; m < image.size() / 2; m++)
            {

                int temp = image[i][m];
                image[i][m] = image[i][image.size() - 1 - m];
                image[i][image.size() - 1 - m] = temp;
            }

            for (int m = 0; m < image.size(); m++)
            {
                if (image[i][m] == 0)
                    image[i][m] = 1;
                else
                    image[i][m] = 0;

            }
        }
        return image;
    }
};
// @lc code=end

