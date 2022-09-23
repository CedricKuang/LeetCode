#include <vector>
#include <unordered_map>
using namespace std;

vector<int> swap_array(vector<int>& v1, vector<int>& v2)
{
    int v1_sum = 0;
    int v2_sum = 0;
    for (int i = 0; i < v1.size(); i++)
        v1_sum += v1[i];
    for (int i = 0; i < v2.size(); i++)
        v2_sum += v2[i];

    if ((v1_sum + v2_sum) % 2 == 1)
        return {-1, -1};

    int new_sum = (v1_sum + v2_sum) / 2;
    unordered_map<int, int> table_v1;
    for (int i = 0; i < v1.size(); i++)
    {
        table_v1[v1_sum - v1[i]] = i;
    }


    for (int i = 0; i < v2.size(); i++)
    {
        if (table_v1.count(new_sum - v2[i]) != 0)
        {
            return {i, table_v1[new_sum - v2[i]]};
        }
    }
    return {-1, -1};

}


int main()
{
    return 0;
}