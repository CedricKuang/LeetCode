#include <string>
using namespace std;

string check_queen(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 || y1 == y2)
        return "YES";
    else if (abs(x1 - x2) == abs(y1 - y2))
        return "YES";
    return "NO";
}

int main()
{
    return 0;
}