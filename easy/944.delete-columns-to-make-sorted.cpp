/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for (int i = 0; i < strs[0].size(); i++)
        {
            string temp = "";
            for (int m = 0; m < strs.size(); m++)
            {
                temp += strs[m][i];
            }
            string temp_sort = temp;
            sort(temp_sort.begin(), temp_sort.end());
            if (temp != temp_sort)
                ans++;
        }
        return ans;
    }
};
// @lc code=end

