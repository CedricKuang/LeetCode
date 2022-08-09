/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> path_table;
        unordered_set<string> childs;
        for (int i = 0; i < paths.size(); i++)
        {
            path_table[paths[i][0]] = paths[i][1];
            childs.insert(paths[i][1]);
        }

        string root = "";
        for (int i = 0; i < paths.size(); i++)
        {
            if (childs.count(paths[i][0]) == 0)
            {
                root = paths[i][0];
                break;
            }
        }

        unordered_map<string, string>::iterator it = path_table.find(root);
        while (it != path_table.end())
        {
            root = it->second;
            it = path_table.find(root);
        }
        return root;
    }
};
// @lc code=end

