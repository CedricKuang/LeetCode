/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;
    string curr = "";

    void back_track(int left_paren, int right_paren, int n)
    {
        if (curr.length() == 2*n)
        {
            ans.push_back(curr);
            return;
        }

        if (left_paren < n)
        {
            curr += "(";
            back_track(left_paren + 1, right_paren, n);
            curr.pop_back();
        }
        
        if (right_paren < left_paren)
        {
            curr += ")";
            back_track(left_paren, right_paren + 1, n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        back_track(0, 0, n);
        return ans;
    }
};
// @lc code=end

