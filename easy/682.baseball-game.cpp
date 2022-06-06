/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> score;
        for (int i = 0; i < ops.size(); i++)
        {
            if (ops[i] == "+")
            {
                int a = score.top();
                score.pop();
                int b = score.top();
                score.push(a);
                score.push(a + b);
            }
            else if (ops[i] == "D")
            {
                score.push(2 * score.top());
            }
            else if (ops[i] == "C")
            {
                score.pop();
            }
            else
                score.push(stoi(ops[i]));
        }
        int ans = 0;
        while (!score.empty()) {
            ans += score.top();
            score.pop();
        }
        return ans;

    }
};
// @lc code=end

