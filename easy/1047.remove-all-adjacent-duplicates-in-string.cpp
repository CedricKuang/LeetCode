/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> m_stack;
        for (int i = 0; i < s.length(); i++)
        {
            if (m_stack.empty() || m_stack.top() != s[i])
                m_stack.push(s[i]);
            else
                m_stack.pop();
        }
        string ans = "";
        while (!m_stack.empty())
        {
            ans = m_stack.top() + ans;
            m_stack.pop();
        }
        return ans;
        
    }
};
// @lc code=end

