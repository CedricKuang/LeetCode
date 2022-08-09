/*
 * @lc app=leetcode id=1417 lang=cpp
 *
 * [1417] Reformat The String
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reformat(string s) {
        vector<char> nums;
        vector<char> chars;
        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
                chars.push_back(s[i]);
            else
                nums.push_back(s[i]);
        }
        // cout << nums.size() << " " << chars.size() << endl;
        int num_size = nums.size();
        int char_size = chars.size();
        if (abs((num_size - char_size)) > 1)
        {
            return "";
        }
            
        string ans = "";
        int i = 0;
        while (!nums.empty() || !chars.empty())
        {
            if (i == 0)
            {
                if (nums.size() > chars.size())
                {
                    ans += nums[nums.size() - 1];
                    nums.pop_back();
                }
                else
                {
                    ans += chars[chars.size() - 1];
                    chars.pop_back();
                }
            }
            else
            {
                if (isalpha(ans[i - 1]))
                {
                    ans += nums[nums.size() - 1];
                    nums.pop_back();
                }
                else
                {
                    ans += chars[chars.size() - 1];
                    chars.pop_back();
                }
            }
            i++;
        }
        return ans;
    }
};
// @lc code=end

