/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int a = 0;
        string answer = "";
        for(;; a++) 
        {
            vector<string>::iterator it = strs.begin();
            if (strs.size() == 1)
            {
                answer = *it;
                return answer;
            }
            if (a >= it->length())
                return answer;
            char comp = (*it)[a];
            it++;
            int i = 2;

            for (; it != strs.end(); it++, i++)
            {
                const string temp = *it;
                if (a >= temp.length())
                    return answer;
                if (temp[a] != comp)
                    return answer;
                if (temp[a] == comp && i == strs.size())
                    answer += comp;
            }
        }
        return answer;
    }
};
// @lc code=end

