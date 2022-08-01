#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct error_flags {
    bool left_paren = false;
    bool parent = false;
    bool child = false;
    bool right_paren = false;
    bool comma = false;
};

bool check_cycle(unordered_map<char, unordered_set<char>>& table, char n, unordered_set<char>& visit)
{
    if (visit.count(n) != 0)
        return true;
    
    visit.insert(n);
    
    unordered_map<char, unordered_set<char>>::iterator it = table.find(n);
    if (it == table.end())
        return false;
    
    unordered_set<char>::iterator it2 = it->second.begin();
    if (it->second.size() == 1)
        return check_cycle(table, *it2, visit);
    unordered_set<char>::iterator it3 = it2;
    it3++;
    return check_cycle(table, *it2, visit) || check_cycle(table, *it3, visit);
}

// a helper function used to construct the s expression 
string construct_expression(unordered_map<char, unordered_set<char>>& table, char n)
{
    unordered_map<char, unordered_set<char>>::iterator it = table.find(n);
    string s_expression = "(";
    s_expression += n;

    if (it == table.end())
    {
        s_expression += ")";
        return s_expression;
    }
    

    unordered_set<char>::iterator it2 = it->second.begin();
    if (it->second.size() == 1)
        return s_expression + construct_expression(table, *it2) + ")";
    
    unordered_set<char>::iterator it3 = it2;
    it3++;
    if (*it2 < *it3)
        return (s_expression + construct_expression(table, *it2) + construct_expression(table, *it3) + ")");
    return (s_expression + construct_expression(table, *it3) + construct_expression(table, *it2) + ")");

}

string get_error(string input)
{
    // check E1: invalid format
    error_flags err;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ' ')
        {
            if (err.child == false || err.comma == false || err.left_paren == false || err.parent == false || err.right_paren == false)
                return "E1 spaces";
            else
            {
                err.child = false;
                err.comma = false;
                err.left_paren = false;
                err.parent = false;
                err.right_paren = false;
            }
        }
        else if (input[i] == '(')
        {
            if (err.child == true || err.comma == true || err.left_paren == true || err.parent == true || err.right_paren == true)
                return "E1 left_apren";
            else
                err.left_paren = true;
        }
        else if (isupper(input[i]))
        {
            if (err.left_paren == false || err.right_paren == true || (err.child == true && err.parent == true))
                return "E1 uppercase";
            else if (err.child == false && err.parent == false)
            {
                if (err.comma == true)
                    return "E1 comma & uppercase";
                else
                    err.parent = true;
            }
            else
            {
                if (err.comma == false)
                    return "E1 comma & uppercase";
                else
                    err.child = true;
            }
        }
        else if (input[i] == ',')
        {
            if (err.child == true || err.comma == true || err.left_paren == false || err.parent == false || err.right_paren == true)
                return "E1 comma";
            else
                err.comma = true;
        }
        else if (input[i] == ')')
        {
            if (err.child == false || err.comma == false || err.left_paren == false || err.parent == false || err.right_paren == true)
                return "E1 right_paren";
            else 
                err.right_paren = true;
        }
        else
            return "E1 others";
    }
    if (err.child == false || err.comma == false || err.left_paren == false || err.parent == false || err.right_paren == false)
        return "E1 space";

    // check E2 and E3: duplicate pair and child number
    unordered_map<char, unordered_set<char>> table;
    unordered_set<char> child_set;
    for (int i = 1; i < input.length(); i+=6)
    {
        if (table[input[i]].count(input[i + 2]) != 0)
            return "E2 duplicate";
        else
        {
            table[input[i]].insert(input[i + 2]);
            child_set.insert(input[i + 2]);
        }
        
        if (table[input[i]].size() > 2)
            return "E3 more than 2 childs";
    }

    // check E4: multiple root
    char root = ' ';
    for (unordered_map<char, unordered_set<char>>::iterator it = table.begin(); it != table.end(); it++)
    {
        if (child_set.count(it->first) == 0)
        {
            if (root == ' ')
                root = it->first;
            else
                return "E4 multiple root";
        }
    }

    // check E5: cycle
    unordered_set<char> visit;
    if (root == ' ' || check_cycle(table, root, visit))
        return "E5 cycle";

    // Now the tree is valid, we construct the s-expression
    string s_expression = construct_expression(table, root);

    return s_expression;
}


int main()
{
    string str = "(A,B) (A,C) (B,D) (D,E) (C,F) (E,G)";
    cout << get_error(str) << endl;
    return 0;
}