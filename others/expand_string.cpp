#include <stack>
#include <string>
#include <iostream>
using namespace std;

string expand_string(string& s)
{
    string ans = "";
    stack<string> stk;
    string temp = "";
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == ')')
        {
            if (temp != "" || (s[i - 1] == '(' && s[i] == ')') ||  (s[i] == '(' && s[i - 1] == '('))
                stk.push(temp);
            temp = "";
        }
        else if (s[i] == '{' || s[i] == '}')
            continue;
        else if (isdigit(s[i]))
        {
            string temp3 = stk.top();
            string temp2 = stk.top();
            stk.pop();
            for (int j = 1; j < ((int)s[i] - 48); j++)
                temp3 += temp2;
            if (stk.empty())
                ans += temp3;
            else
            {
                temp2 = stk.top();
                temp2 += temp3;
                stk.pop();
                stk.push(temp2);
            }
        }
        else
            temp += s[i];
    }
    return ans;
}

string curr = "";
    int num = 0;
    stack<string> stk;

    for (int i = 0; i < inputStr.length(); i++)
    {
        char c = inputStr[i];
        if (isdigit(c))
        {
            num = num + ((int)c - 48);
        }

        else if (isalpha(c))
        {
            curr = curr + c;
        }

        else if (c == '(')
        {
            stk.push(curr);
            curr = "";
        }

        else if (c == '}')
        {
            string old_string = stk.top();
            stk.pop();
            string new_string = "";
            while (num > 0)
            {
                new_string += old_string;
                num--;
            } 
            curr = old_string + new_string;
        }
    }

    string ans;
    while (!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    ans += curr;
    return ans;

int main()
{
    string test = "(ab(c){3}d){2}";
    cout << expand_string(test) << endl;
}