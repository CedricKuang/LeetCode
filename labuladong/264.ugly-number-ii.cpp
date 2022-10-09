/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 1, p3 = 1, p5 = 1;
        int product2 = 1, product3 = 1, product5 = 1;
        vector<int> ugly(n + 1);
        int p = 1;

        while (p <= n)
        {
            int min_num = min(min(product2, product3), product5);
            ugly[p] = min_num;
            p++;

            if (min_num == product2)
            {
                product2 = 2 * ugly[p2];
                p2++;
            }
            if (min_num == product3)
            {
                product3 = 3 * ugly[p3];
                p3++;
            }
            if (min_num == product5)
            {
                product5 = 5 * ugly[p5];
                p5++;
            }
        }
        return ugly[n];
    }
};
// @lc code=end

