/*
 * @lc app=leetcode id=1812 lang=cpp
 *
 * [1812] Determine Color of a Chessboard Square
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if (coordinates[0] == 'a' || coordinates[0] == 'c' || coordinates[0] == 'e' || coordinates[0] == 'g')
        {
            if (((int)coordinates[1] - 48) % 2 == 0)
                return true;
            else
                return false;
        }
        else
        {
            if (((int)coordinates[1] - 48) % 2 == 0)
                return false;
            else
                return true;
        }
    }
};
// @lc code=end

