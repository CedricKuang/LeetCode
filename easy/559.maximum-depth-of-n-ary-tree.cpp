/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
/*
// Definition for a Node.*/
#include <vector>
using namespace std;
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };


class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        
        int max_depth = 0;
        for (int i = 0; i < root->children.size(); i++)
        {
            int depth = maxDepth(root->children[i]);
            if (depth > max_depth)
                max_depth = depth;
        }

        return (max_depth + 1);
    }
};
// @lc code=end

