#include <vector>
#include <iostream>
using namespace std;

vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int DaysInMonth(int year, int month)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        if (month == 2)
            return days_in_month[1] + 1;
    }
    return days_in_month[month - 1];
}

int DaysBetween(int y1, int m1, int d1, int y2, int m2, int d2)
{
    if (y1 == y2 && m1 == m2)
        return d2 - d1 + 1; 
    int ans = (DaysInMonth(y1, m1) - d1) + d2;
    for (int i = y1; i <= y2; i++)
    {
        if (i == y1 || i == y2)
        {
            int month = 1;
            int end = 12;
            if (i == y1)
                month = m1 + 1;
            if (i == y2)
                end = m2 - 1;
            while (month <= end)
            {
                ans += DaysInMonth(i, month);
                month++;
            }
        }
        else
            ans += (DaysInMonth(i, 2) == 28 ? 365 : 366);
    }
    return ans;

}


int main()
{
    cout << DaysBetween(2014, 8, 1, 2014, 8, 22) << endl;
    return 0;
}