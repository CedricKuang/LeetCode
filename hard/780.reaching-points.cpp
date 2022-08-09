/*
 * @lc app=leetcode id=780 lang=cpp
 *
 * [780] Reaching Points
 */

// @lc code=start
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx < sx || ty < sy)
            return false;
        if (sx == tx)
        {
            return (ty - sy) % sx == 0;
        }
        if (sy == ty)
        {
            return (tx - sx) % sy == 0;
        }

        while (tx > sx && ty > sy)
        {
            if (tx > ty)
                tx %= ty;
            else
                ty %= tx;
        }

        if (tx == sx)
        {
            if((ty - sy) % tx == 0)
                return true;
        } else if(ty == sy) {
            if((tx - sx) % ty == 0)
                return true;
        }
        
        return false;
    }
};
// @lc code=end

