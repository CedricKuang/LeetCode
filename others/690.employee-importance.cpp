/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> table;
        for (int i = 0; i < employees.size(); i++)
            table[employees[i]->id] = employees[i];
        int ans = 0;
        queue<int> my_queue;
        my_queue.push(id);
        while (!my_queue.empty())
        {
            int front_id = my_queue.front();
            my_queue.pop();
            Employee* curr = table[front_id];
            ans += curr->importance;
            for (int i = 0; i < curr->subordinates.size(); i++)
                my_queue.push(curr->subordinates[i]);
        }
        return ans;
    }
};
// @lc code=end

