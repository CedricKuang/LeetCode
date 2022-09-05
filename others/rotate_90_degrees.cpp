#include <vector>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& image)
{
    int row = image.size();
    int col = image[0].size();
    vector<vector<int>> ans(col, vector<int>(row));
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            ans[i][j] = image[row - 1 - j][i];
        }
    }
    return ans;
}

int main()
{
    return 0;
}