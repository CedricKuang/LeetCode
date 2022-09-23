#include <vector>
using namespace std;

int ans = 0;
vector<vector<int>> checked(9, vector<int>(9));

void BFS(int start_x, int start_y, int des_x, int des_y, int depth)
{
    if (start_x < 0 || start_y > 8 || checked[start_x][start_y] == 1)
        return;
    if (start_x == des_x && start_y == des_y)
    {
        if (depth < ans)
            ans = depth;
        return;
    }
    checked[start_x][start_y] = 1;
    BFS(start_x + 2, start_y + 1, des_x, des_y, depth + 1);
    BFS(start_x + 2, start_y - 1, des_x, des_y, depth + 1);
    BFS(start_x + 1, start_y + 2, des_x, des_y, depth + 1);
    BFS(start_x + 1, start_y - 2, des_x, des_y, depth + 1);
    BFS(start_x - 2, start_y + 1, des_x, des_y, depth + 1);    
    BFS(start_x - 2, start_y - 1, des_x, des_y, depth + 1);
    BFS(start_x - 1, start_y + 2, des_x, des_y, depth + 1);
    BFS(start_x - 1, start_y - 2, des_x, des_y, depth + 1);
}


int check_knight(int start_x, int start_y, int des_x, int des_y)
{
    BFS(start_x, start_y, des_x, des_y, 0);
    return ans;
}


int main()
{
    return 0;
}