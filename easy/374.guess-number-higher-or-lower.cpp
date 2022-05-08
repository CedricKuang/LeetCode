/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long low = 1;
        long long high = n;
        int guess_result = guess((high + low) / 2);
        while (guess_result != 0)
        {
            if (guess_result == -1)
                high = ((high + low) / 2) - 1;
            else if (guess_result == 1)
                low = ((high + low) / 2) + 1;
            guess_result = guess((high + low) / 2);
        }
        return (high + low) / 2;
    }
};
// @lc code=end

