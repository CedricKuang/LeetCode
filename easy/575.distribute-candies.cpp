/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

// @lc code=start
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int num_eat = 0;
        int max_eat = candyType.size() / 2;
        unordered_set<int> table;
        for (int i = 0; i < candyType.size(); i++)
        {
            unordered_set<int>::iterator it = table.find(candyType[i]);
            if (it == table.end())
            {
                num_eat++;
                table.insert(candyType[i]);
            }

            if (num_eat == max_eat)
                return num_eat;
        }
        return num_eat;
    }
};
// @lc code=end

