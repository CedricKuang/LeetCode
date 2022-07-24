/*
 * @lc app=leetcode id=1154 lang=cpp
 *
 * [1154] Day of the Year
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        int ans = 0;

        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int years = stoi(date.substr(0, 4));
        if ((years % 4 == 0 && years % 100 != 0) || (years % 100 == 0 && years % 400 == 0))
            days[1]++;

        int months = 0;
        if (date[5] == '0') 
            months = stoi(date.substr(6, 1));
        else
            months = stoi(date.substr(5, 2));
        
        for (int i = 0; i < months - 1; i++)
            ans += days[i];
        
        int day = 0;
        if (date[8] == '0') 
            day = stoi(date.substr(9, 1));
        else
            day = stoi(date.substr(8, 2));
        
        ans += day;
        return ans;

    }
};
// @lc code=end

