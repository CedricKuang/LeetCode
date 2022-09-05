#include <iostream>
using namespace std;

int count_bits(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += (x % 2);
        x /= 2;
    }
    return ans;
}

int main()
{
    cout << count_bits(18) << endl;
    return 0;
}