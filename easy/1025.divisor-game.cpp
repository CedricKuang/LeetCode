/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 */

// @lc code=start
class Solution {
public:
    int find_divisible (int n)
    {
        for (int i = 1; i < n; i++)
            if (n % i == 0)
                return i;
        return -1;

    }
    bool divisorGame(int n) {
        bool is_alice = true;
        while (n > 1)
        {
            int mod = find_divisible(n);
            if (mod == -1)
                return !is_alice;
            n = n - mod;
            is_alice = !is_alice;
        }
        return !is_alice;
    }
};
// @lc code=end

