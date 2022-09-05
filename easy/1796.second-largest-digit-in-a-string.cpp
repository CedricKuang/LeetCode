/*
 * @lc app=leetcode id=1796 lang=cpp
 *
 * [1796] Second Largest Digit in a String
 */

// @lc code=start
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        set<int> digits;
	for (char c : s)
		if (isdigit(c))
			digits.insert(c - '0');
	if (digits.size() < 2)
		return -1;
	auto resIt = digits.rbegin();
	return *(++resIt);
    }
};
// @lc code=end

