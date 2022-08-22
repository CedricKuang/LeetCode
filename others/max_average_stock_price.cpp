#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int max_average_stock_price(vector<int>& stock, int k)
{
    int curr_sum = 0;
    int max_sum = 0;
    unordered_set<int> window;
    unordered_map<int, int> indexes;
    vector<long> prefix_sums(stock.size());
    prefix_sums[0] = 0;
    int left = 0, right = 0;

    while (right < stock.size())
    {
        curr_sum += stock[right];
        if (right > 0)
            prefix_sums[right] = prefix_sums[right - 1] + stock[right - 1];

        if (window.count(stock[right]) > 0 && indexes[stock[right]] >= left)
        {
            // while (left <= indexes[stock[right]])
            // {
            //     curr_sum -= stock[left];
            //     window.erase(stock[left]);
            //     left++;
            // }
            int next_left = indexes[stock[right]] + 1;
            curr_sum = curr_sum - (prefix_sums[next_left] - prefix_sums[left]);
            left = next_left;
        }

        indexes[stock[right]] = right;
        window.insert(stock[right]);

        // cout << curr_sum << endl;
        

        if (right - left + 1 == k)
        {
            max_sum = max(max_sum, curr_sum);
            curr_sum -= stock[left];
            window.erase(stock[left]);
            left++;
        }
        right++;
    }

    return max_sum;
}


int main()
{
    vector<int> test = {1, 2, 2, 7, 5, 4, 2, 12};
    cout << max_average_stock_price(test, 3) << endl;
}