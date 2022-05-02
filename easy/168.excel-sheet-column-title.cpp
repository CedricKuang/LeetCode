/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
	    while(columnNumber){
		    columnNumber -= 1;
		    ans = (char)(columnNumber % 26 + 'A') + ans;
		    columnNumber /= 26;
	    }
	    return ans;
    }
};
// @lc code=end

