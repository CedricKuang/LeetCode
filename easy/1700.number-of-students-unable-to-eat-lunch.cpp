/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
 */

// @lc code=start
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> queue_students;
        stack<int> stack_sandwiches;
        unordered_map<int, int> nums;
        for (int i = 0; i < students.size(); i++)
        {
            queue_students.push(students[i]);
            stack_sandwiches.push(sandwiches[sandwiches.size() - 1 -i]);
            nums[students[i]]++;
        }

        while (!queue_students.empty() && !stack_sandwiches.empty())
        {
            int front_student = queue_students.front();
            int top_sandwich = stack_sandwiches.top();
            if (front_student == top_sandwich)
            {
                queue_students.pop();
                stack_sandwiches.pop();
                nums[front_student]--;
            }
            else
            {
                if (nums[top_sandwich] == 0)
                    break;
                else
                {
                    queue_students.pop();
                    queue_students.push(front_student);
                }
            }
        }
        
        return queue_students.size();

    }
};
// @lc code=end

