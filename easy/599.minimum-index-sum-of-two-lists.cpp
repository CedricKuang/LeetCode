/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        map<string, int> table;
        int min_sum = 3000;
        for (int i = 0; i < list1.size(); i++)
            table.insert(pair<string, int>(list1[i], i));
        for (int i = 0; i < list2.size(); i++)
        {
            map<string, int>::iterator it = table.find(list2[i]);
            if (it != table.end())
            {
                if (it->second + i < min_sum)
                {
                    result.clear();
                    result.push_back(list2[i]);
                    min_sum = it->second + i;
                }
                else if (it->second + i == min_sum)
                    result.push_back(list2[i]);
            }
        }
        return result;
    }
};
// @lc code=end

