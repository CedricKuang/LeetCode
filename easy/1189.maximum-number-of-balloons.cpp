/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string date) {
        unordered_map<char, int> table;
        for (int i = 0; i < date.size(); i++)
        {
            if (date[i] == 'b' || date[i] == 'a' || date[i] == 'l' || date[i] == 'o' || date[i] == 'n')
                table[date[i]]++;
        }
        string balloon = "balloon";
        int i = 0;
        int ans = 0;
        while (!table.empty())
        {
            unordered_map<char, int>::iterator it = table.find(balloon[i]);
            if (it == table.end())
                break;
            else
            {
                it->second--;
                if (it->second == 0)
                    table.erase(it);
                if (i == 6)
                {
                    ans++;
                    i = 0;
                }
                else
                    i++;
            }
        }
        return ans;
        
    }
};
// @lc code=end

