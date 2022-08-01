/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, vector<int>> table;
        set<int> bits;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            int temp = arr[i];
            int bit = 0;
            while (temp > 0)
            {
                bit += (temp % 2);
                temp /= 2;
            }
            bits.insert(bit);
            table[bit].push_back(arr[i]);
        }

        // sort(bits.begin(), bits.end());
        for (set<int>::iterator it = bits.begin(); it != bits.end(); it++)
        {
            int curr_bit = *it;
            sort(table[curr_bit].begin(), table[curr_bit].end());
            for (int m = 0; m < table[curr_bit].size(); m++)
            {
                ans.push_back(table[curr_bit][m]);
            }
        }
        return ans;

    }   
};
// @lc code=end

