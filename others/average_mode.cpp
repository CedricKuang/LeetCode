#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> get_average_and_mode(vector<int>& nums)
{
    int avg = 0;
    unordered_map<int, int> table;
    for (int i = 0; i < nums.size(); i++)
    {   
        avg += nums[i];
        table[nums[i]]++;
    }

    int max_freq = 0;
    int mode = 0;
    for (int i = 0; i < nums.size(); i++)
    {   
        if (table[nums[i]] > max_freq)
        {
            max_freq = table[nums[i]];
            mode = nums[i];
        }
    }
    avg = avg / nums.size();
    return {avg, mode};
}


int main()
{
    return 0;
}