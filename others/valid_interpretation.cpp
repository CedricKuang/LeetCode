#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;


void helper(string s, int& count, int pos)
{
    if (pos == s.length())
    {
        count++;
        return;
    }

    int num = 0;
    for (int i = pos; i < s.length(); i++)
    {
        num = num * 10 + ((int)s[i] - 48);
        if (num >= 0 && num <= 25)
        {
            helper(s, count, pos + 1);
        }
        else
            break;

        if (num == 0)
            break;
    }
    return;
}

int valid_representation(string& s)
{
    int count = 0;
    helper(s, count, 0);
    return count;
}

// int valid_representation2(string s)
// {
//     if (s.length() == 1)
//         return 1;
    
//     if (s[0] == '0')
//     {
//         return 1 + valid_representation2(s.substr(1));
//     }
//     else
//     {
//         int num = ((int)s[0] - 48) * 10 + (int)s[1];
//         if (num > 25)
//         {
//             return 1 + valid_representation2(s.substr(1));
//         }
//         else
//         {
//             return 2 + valid_representation2(s.substr(1)) + valid_representation2(s.substr(2));
//         }
//     }

// }

int main()
{
    string test = "100200300";
    cout << valid_representation(test) << endl;
    return 0;
}