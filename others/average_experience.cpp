#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int differen_experience_level(vector<int>& experience)
{
    sort(experience.begin(), experience.end());
    unordered_set<double> final_levels;
    int n = experience.size();
    
    for (int i = 0; i < n / 2; i++)
    {
        final_levels.insert(((double)(experience[i] + experience[n - i - 1]) / 2));
    }
    return final_levels.size();
}



int main()
{
    std::vector<int> test = {1, 2, 3, 3, 4, 5};
    int result = differen_experience_level(test);
    cout << result << endl;
    return 0;
}