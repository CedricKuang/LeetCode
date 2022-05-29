/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int late = 0;
        int abs = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                abs++;
                late = 0;
            }
            else if (s[i] == 'L')
                late++;
            else 
                late = 0;
            
            if (late == 3 || abs >= 2)
                return false;
        }
        return true;
    }
};
// @lc code=end

