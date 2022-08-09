#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> crossing_street(vector<int>& a, vector<int>& b)
{
    vector<int> ans(a.size(), 0);
    int curr_time = 0;
    int last = -1;
    queue<vector<int>> avenue;
    queue<vector<int>> street;
    for (int i = 0; i < a.size(); i++)
    {
        if (b[i] == 1)
        {
            avenue.push({a[i], i});
        }
        else
        {
            street.push({a[i], i});
        }
    }

    while (!avenue.empty() || !street.empty())
    {

        vector<int> curr_ave;
        if (avenue.empty())
            curr_ave = {};
        else
            curr_ave = avenue.front();
        
        vector<int> curr_str; 
        if (street.empty())
            curr_str = {};
        else
            curr_str = street.front();

        if (last == -1 || last == 1)
        {
            if (!curr_ave.empty() && curr_ave[0] <= curr_time)
            {
                avenue.pop();
                ans[curr_ave[1]] = curr_time;
                last = 1;
            }
            else if (!curr_str.empty() && curr_str[0] <= curr_time)
            {
                street.pop();
                ans[curr_str[1]] = curr_time;
                last = 0;
            }
            else
                last = -1;
        }     
        else
        {
            if (!curr_str.empty() && curr_str[0] <= curr_time)
            {
                street.pop();
                ans[curr_str[1]] = curr_time;
                last = 0;
            }
            else if (!curr_ave.empty() && curr_ave[0] <= curr_time)
            {
                avenue.pop();
                ans[curr_ave[1]] = curr_time;
                last = 1;
            }
            else
                last = -1;
        }  
        curr_time++;
    }

    return ans;
}



int main()
{
    vector<int> a = {0, 1, 1, 3, 3};
    vector<int> b = {0, 1, 0, 0, 1};
    vector<int> ans = crossing_street(a, b);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}