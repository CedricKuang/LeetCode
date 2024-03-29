/*
 * @lc app=leetcode id=1720 lang=cpp
 *
 * [1720] Decode XORed Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans(encoded.size() + 1);
        ans[0] = first;
        for (int i = 0; i < encoded.size(); i++)
        {
            ans[i + 1] = encoded[i] ^ ans[i];
        }
        return ans;
    }
};
// @lc code=end

