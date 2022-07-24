/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int find_max_index(vector<int>& stones)
    {
        int max = stones[0];
        int max_index = 0;
        for (int i = 1; i < stones.size(); i++)
        {
            if (stones[i] > max)
            {
                max = stones[i];
                max_index = i;
            }
        }
        return max_index;
    }

    int find_second_max(vector<int>& stones, int max_index)
    {
        int max = stones[max_index];
        int second_max, index;
        if (max_index != 0)
        {
            second_max = stones[0];
            index = 0;  
        }
        else
        {
            second_max = stones[1];
            index = 1;  
        }
        
        for (int i = 0; i < stones.size(); i++)
        {
            if ((max - stones[i] < max - second_max) && max_index != i)
            {
                second_max = stones[i];
                index = i;
            }
        }
        return index;
    }

    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1)
            return stones[0];
        
        int max_index = find_max_index(stones);
        int second_index = find_second_max(stones, max_index);
        // cout << max_index << " " << second_index << endl;
        if (stones[max_index] == stones[second_index])
        {
            if (max_index > second_index)
            {
                stones.erase(stones.begin() + max_index);
                stones.erase(stones.begin() + second_index);
            }
            else
            {
                stones.erase(stones.begin() + second_index);
                stones.erase(stones.begin() + max_index);
            }
        }
        else
        {
            stones[max_index] -= stones[second_index];
            stones.erase(stones.begin() + second_index);
        }
        if (stones.size() == 0)
            return 0;
        return lastStoneWeight(stones);

    }
};
// @lc code=end

