#include <iostream>
#include <vector>
using namespace std;

vector<int> largest_full_sqaure(vector<vector<int>>& image)
{
    int i = -1, j = -1, m = 0;
    int N = image.size();
    for (int p = 0; p < N - 1; p++)
    {
        for (int q = 0; q < N - 1; q++)
        {
            if (p != N - 1 && q != N - 1)
            {
                if (image[p + 1][q + 1] != 0)
                {
                    image[p + 1][q + 1] = min(image[p][q], min(image[p + 1][q], image[p][q + 1])) + 1;
                }
            }

            if (image[p][q] > m)
            {
                m = image[p][q];
                i = p - m + 1;
                j = q - m + 1;
            }
        }
    }

    return {i, j, m};
}


int main()
{
    vector<vector<int>> image = {
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 0, 0, 1},
    };

    vector<int> ans = largest_full_sqaure(image);
    for (int i = 0; i < 3; i++)
        cout << ans[i] << " ";          // should print out "0 0 4"
    return 0;
}