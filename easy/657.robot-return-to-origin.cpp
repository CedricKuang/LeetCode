/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0;
        int down = 0;
        int left = 0;
        int right = 0;
        for (int i = 0; i < moves.length(); i++)
        {
            if (moves[i] == 'R')
                right++;
            else if (moves[i] == 'L')
                left++;
            else if (moves[i] == 'U')
                up++;
            else 
                down++;

        }        

        return (right == left) && (up == down);
    }
};
// @lc code=end

