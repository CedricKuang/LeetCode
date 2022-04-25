/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 1; i <= numRows; i++)
        {
            vector<int> row;
            if (i == 1)
            {
                row.push_back(1);
                result.push_back(row);
            }
            else
            {
                for (int m = 1; m <= i; m++)
                {
                    if (m == 1 || m == i)
                        row.push_back(1);
                    else
                    {
                        int val = result[i-1-1][m-1-1] + result[i-1-1][m-1];
                        row.push_back(val);
                    }
                        
                }
                result.push_back(row);
            }
        }
        return result;
    }
};
// @lc code=end

