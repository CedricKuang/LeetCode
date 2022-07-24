/*
 * @lc app=leetcode id=1184 lang=cpp
 *
 * [1184] Distance Between Bus Stops
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (destination < start)
        {
            swap(start, destination);
        }

        int clock_wise_distance = 0;
        int counter_clock_wise_distance = 0;
        int total_distance = 0;
        for (int i = start; i < destination; i++)
        {
            if (i == distance.size())
                i = 0;
            clock_wise_distance += distance[i];
        }

        for (int i = 0; i < distance.size(); i++)
            total_distance += distance[i];
        counter_clock_wise_distance = total_distance - clock_wise_distance;
        // cout << counter_clock_wise_distance << " " << clock_wise_distance << endl;
        return clock_wise_distance < counter_clock_wise_distance ? clock_wise_distance : counter_clock_wise_distance;
    }
};
// @lc code=end

