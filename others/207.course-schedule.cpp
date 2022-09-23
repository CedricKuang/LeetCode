/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    unordered_set<int> visited;
    unordered_set<int> on_path;
    bool has_cycle = false;

    vector<vector<int>> build_graph(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        return graph;
    }

    void DFS(vector<vector<int>>& graph, int num)
    {
        
        if (has_cycle)
            return;
        if (on_path.count(num) == 1)
        {
            has_cycle = true;
            return;
        }
        if (visited.count(num) == 1)
            return;

        visited.insert(num);
        on_path.insert(num);
        for (int i = 0; i < graph[num].size(); i++)
        {
            DFS(graph, graph[num][i]);
        }
        on_path.erase(num);
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = build_graph(numCourses, prerequisites);
        for (int i = 0; i < numCourses; i++)
            DFS(graph, i);
        return !has_cycle;
    }
};
// @lc code=end

