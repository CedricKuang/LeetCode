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
    vector<int> answer;
    vector<int> preorder(Node* root) {
        if (root == nullptr)
            return answer;
        
        answer.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++)
            preorder(root->children[i]);
        return answer;
    }
};
// @lc code=end

