#include <vector>
using namespace std;

vector<int> check_prime_numbers(vector<int>& nums)
{
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        int n = nums[i];
        for (int j = 2; j <= n / 2; j++)
        {
            if (n % j == 0)
            {
                ans[i] = 1;
                break;
            }
        }
    }
    return ans;
}


int main()
{
    return 0;
}