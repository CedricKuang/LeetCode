#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

bool check_square(int x, int y)
{
    int s = sqrt(x + y);
    return ((s * s) == (x + y));
}

bool reaching_point(int sx, int sy, int tx, int ty, int c)
{
    if (tx < sx || ty < sy)
        return false;
    else if (check_square(sx, sy))
        return false;
    else if (tx == sx && ty == sy)
        return true;
    
    if (tx == sx)
    {
        return reaching_point(sx, sx + sy, tx, ty, c);
    }
    else if (ty == sy)
    {
        return reaching_point(sx + sy, sy, tx, ty, c);
    }
    else 
    {
        return reaching_point(sx, sx + sy, tx, ty, c) || reaching_point(sx + sy, sy, tx, ty, c)
            || reaching_point(sx + c, sy + c, tx, ty, c);
    }
}

bool reaching_point_stack(int sx, int sy, int tx, int ty, int c)
{
    stack<int> stk_x, stk_y;
    vector<vector<int>> visit(tx + 1, vector<int>(ty + 1));
    stk_x.push(sx);
    stk_y.push(sy);
    
    while(!stk_x.empty() && !stk_y.empty())
    {
        int curr_x = stk_x.top();
        stk_x.pop();
        int curr_y = stk_y.top();
        stk_y.pop();
        if (curr_x > tx || curr_y > ty || check_square(curr_x, curr_y) || visit[curr_x][curr_y] == 1)
            continue;
        else if (curr_x == tx && curr_y == ty)
            return true;
        
        visit[curr_x][curr_y] = 1;
        if (curr_x == tx)
        {
            stk_x.push(curr_x);
            stk_y.push(curr_x + curr_y);
        }
        else if (curr_y == tx)
        {
            stk_x.push(curr_x + curr_y);
            stk_y.push(curr_y);
        }
        else
        {
            stk_x.push(curr_x);
            stk_y.push(curr_x + curr_y);
            stk_x.push(curr_x + curr_y);
            stk_y.push(curr_y);
            stk_x.push(curr_x + c);
            stk_y.push(curr_y + c);
        }
        
    }
    return false;
}

int main()
{
    if (reaching_point_stack(1, 1, 3, 5, 10))
        cout << "Yes" << endl; 
    return 0;
}