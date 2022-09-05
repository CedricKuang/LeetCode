#include <iostream>
using namespace std;

int digit_sum(int numX, int numY)
{
    if (numY > 27 || (numX == 1000 && numY != 1))
        return 0;
    
    int answer = 0;
    int curr_tenth = 0;
    int curr_hundredth = 0;
    int curr_first = 1;
    for (int i = 1; i <= numX; i++)
    {
        if (i % 100 == 0)
        {
            curr_hundredth++;
            curr_tenth = 0;
            curr_first = 0;
        }
        else if (i % 10 == 0)
        {
            curr_tenth++;
            curr_first = 0; 
        }

        if (numY == (curr_first + curr_hundredth + curr_tenth))
            answer++;
        curr_first++;
    }
    return answer;
}


int main()
{
    cout << digit_sum(999, 24) << endl;
    return 0;
}