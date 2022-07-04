/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string toGoatLatin(string sentence) {
        vector<string> set;
        string temp ="";
        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == ' ')
            {
                set.push_back(temp);
                temp = "";
            }
                
            else 
                temp += sentence[i];
        }

        if (temp != "")
            set.push_back(temp);

        string post_fix = "a";
        for (int i = 0; i < set.size(); i++)
        {
            if (tolower(set[i][0]) == 'a' || tolower(set[i][0]) == 'e' || tolower(set[i][0]) == 'i' || tolower(set[i][0]) == 'o' || tolower(set[i][0]) == 'u' )
                set[i] += "ma";
            else
            {
                set[i] += set[i][0];
                set[i].erase(0, 1);
                set[i] += "ma";
            }
            set[i] += post_fix;
            post_fix += "a";
        }

        string result = "";
        for (int i = 0; i < set.size(); i++)
        {
            result += set[i];
            if (i != set.size() - 1)
                result += " ";
        }
        return result;
    }
};
// @lc code=end

