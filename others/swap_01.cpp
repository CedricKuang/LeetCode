#include <vector>
using namespace std;

int minimum_swap(vector<int>& arr)
{
    int left = 0;
    int right = arr.size() - 1;
    
    int left_swaps = 0;
    while (left < right)
    {
        if (arr[left] == 1 && arr[right] == 0)
        {
            left_swaps++;
            left++;
            right--;
        }
        else if  (arr[left] == 1)
        {
            while (arr[right] == 1 && left < right)
            {
                right--;
            }   
        }
    }

    left = 0;
    right = arr.size() - 1;
    int right_swaps = 0;
    while (left < right)
    {
        if (arr[left] == 0 && arr[right] == 1)
        {
            right_swaps++;
            left++;
            right--;
        }
        else if  (arr[left] == 0)
        {
            while (arr[right] == 0 && left < right)
            {
                right--;
            }   
        }
    }
    
    return min(left_swaps, right_swaps);
}


int main()
{
    return 0;
}