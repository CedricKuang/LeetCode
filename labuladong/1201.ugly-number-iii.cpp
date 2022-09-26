/*
 * @lc app=leetcode id=1201 lang=cpp
 *
 * [1201] Ugly Number III
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    long gcd(long a, long b)
    {
        if (a < b)
        {
            return gcd(b, a);
        }
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long lcm(long a, long b)
    {
        return a * b / gcd(a, b);
    }

    long f(int num, int a, int b, int c)
    {
        long setA = num / a, setB = num / b, setC = num / c;
        long setAB = num / lcm(a, b);
        long setAC = num / lcm(a, c);
        long setBC = num / lcm(b, c);
        long setABC = num / lcm(lcm(a, b), c);
        return setA + setB + setC - setAB - setAC - setBC + setABC;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        int left = 1, right = (int) 2e9;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (f(mid, a, b, c) < n)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end

