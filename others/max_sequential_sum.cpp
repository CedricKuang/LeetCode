#include <iostream>
#include <vector>
using namespace std;

int max_sequential_sum(vector<int>& nums)
{
    int curr_sum = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        curr_sum += nums[i];
        if (curr_sum > max_sum)
            max_sum = curr_sum;
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return max_sum;
}

int main()
{
    vector<int> test = {2, -8, 3, -2, 4, -10};
    cout << max_sequential_sum(test) << endl;
    return 0;
}