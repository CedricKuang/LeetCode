/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int max = 0;
        int max_i = 0;
        int min = 2000000;
        int min_i = 0;
        for (int i = 0; i < salary.size(); i++)
        {
            if (salary[i] > max)
            {
                max = salary[i];
                max_i = i;
            }

            if (salary[i] < min)
            {
                min = salary[i];
                min_i = i;
            }
        }

        if (max_i > min_i)
        {
            salary.erase(salary.begin() + max_i);
            salary.erase(salary.begin() + min_i);
        }
        else
        {
            salary.erase(salary.begin() + min_i);
            salary.erase(salary.begin() + max_i);
        }

        double sum = 0;
        for (int i = 0; i < salary.size(); i++)
            sum += salary[i];
        
        return (sum / salary.size());
    }
};
// @lc code=end

