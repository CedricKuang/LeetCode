/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 0; i < n; i++)
        {
            string buzz;
            if (((i + 1) % 5 == 0) && ((i + 1) % 3 == 0))
                buzz = "FizzBuzz";
            else if ((i + 1) % 3 == 0)
                buzz = "Fizz";
            else if ((i + 1) % 5 == 0)
                buzz = "Buzz";
            else 
                buzz = to_string(i + 1);
            result.push_back(buzz);
        }
        return result;
    }
};
// @lc code=end

