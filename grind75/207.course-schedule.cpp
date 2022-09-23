/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

class Solution {
public:
    bool* onPath;
    bool* visited;
    bool has_cycle = false;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildgraph(numCourses, prerequisites);

        visited = new bool[numCourses];
        for (int i = 0; i < numCourses; i++)
            visited[i] = false;
        onPath = new bool[numCourses];
        for (int i = 0; i < numCourses; i++)
            onPath[i] = false;

        for (int i = 0; i < numCourses; i++)
        {
            traverse(graph, i);
        }

        return !has_cycle;
    }

    void traverse(vector<vector<int>>& graph, int s)
    {
        if (onPath[s])
        {
            has_cycle = true;
        }
        
        if (visited[s] || has_cycle)
            return;
        
        visited[s] = true;
        onPath[s] = true;
        for (int i = 0; i < graph[s].size(); i++)
            traverse(graph, graph[s][i]);
        onPath[s] = false;
    }

    vector<vector<int>> buildgraph(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph;
        for (int i = 0; i < numCourses; i++)
        {
            vector<int> temp;
            graph.push_back(temp);
        }
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            graph[from].push_back(to);
        }
        return graph;
    }
};
// @lc code=end

