/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <vector>
using namespace std;


class Solution {
public:
    vector<int> ans;
    void helper(Node* root)
    {
        if (root == nullptr)
            return;
        
        ans.push_back(root->val);
        for (Node* child : root->children)
            helper(child);
        
        return;
    }
    vector<int> preorder(Node* root) {
        helper(root);
        return ans;
    }
};
// @lc code=end

