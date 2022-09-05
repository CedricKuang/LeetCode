#include <vector>
#include <string>
using namespace std;

vector<string> chess_board(int n)
{
    string row1 = "";
    string row2 = "";
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            row1 += "w";
            row2 += "B";
        }
        else
        {
            row1 += "B";
            row2 += "W";
        }
    }

    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            ans.push_back(row1);
        else
            ans.push_back(row2);
    }
    return ans;
}

int main()
{
    return 0;
}