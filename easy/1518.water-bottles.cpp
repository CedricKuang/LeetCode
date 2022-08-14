/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty_bootle = numBottles;
        int have_drink = numBottles;
        numBottles = 0;

        while (empty_bootle >= numExchange)
        {
            numBottles = empty_bootle / numExchange;
            empty_bootle = empty_bootle % numExchange;

            empty_bootle += numBottles;
            have_drink += numBottles;
            numBottles = 0;
        }
        return have_drink;
    }
};
// @lc code=end

