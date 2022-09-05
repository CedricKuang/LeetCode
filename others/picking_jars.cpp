#include <vector>
#include <iostream>
using namespace std;

int picking_jars(vector<int>& jars)
{
    vector<vector<int>> dp(jars.size(), vector<int>(2));
    if (jars.size() == 1)
        return jars[0];
    dp[0][0] = 0;
    dp[0][1] = jars[0];
    for (int i = 1; i < jars.size(); i++)
    {
        dp[i][1] = dp[i - 1][0] + jars[i];
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
    } 
    return max(dp[jars.size() - 1][0], dp[jars.size() - 1][1]);
}

int main()
{
    vector<int> test = {5, 30, 99, 60, 5, 10};
    cout << picking_jars(test) << endl;
    return 0;
}