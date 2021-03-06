/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 */

// @lc code=start
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        std::unordered_map<int, int> map;
        for (int i=0; i<deck.size(); i++) // store in unordered_map the amount of cards with each number
            map[deck[i]]++;
        
        int x = INT_MAX;
        for (std::pair<int, int> num : map) // find minimum
        {
            if (num.second < x)
                x = num.second;
        }
        if (x < 2) return false;
        
        for(int i=2; i<=x;i++) // loop through all numbers smaller than minimum
        {
            bool good = true;
            for (std::pair<int, int> num : map) // if all groups of cards divide by i - flag stays true
            {
                if (num.second % i != 0)
                {
                    good = false;
                    break;
                }
                    
            }
            if (good) return true;
        }
            
        return false;
    }
};
// @lc code=end

