/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> result;
        vector<int> places;
        for (int i = 0; i < score.size(); i++)
        {
            int place = score.size();
            for (int m = 0; m < score.size(); m++)
            {
                if (m == i)
                    continue;
                else if (score[m] < score[i])
                    place--;
            }
            places.push_back(place);
        }

        for (int i = 0; i < places.size(); i++)
        {
            if (places[i] == 1)
                result.push_back("Gold Medal");
            else if (places[i] == 2)
                result.push_back("Silver Medal");
            else if (places[i] == 3)
                result.push_back("Bronze Medal");
            else
                result.push_back(to_string(places[i]));
        }
        return result;
    }
};
// @lc code=end

