/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> ans;
    void helper(TreeNode* root)
    {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        helper(root->left);
        helper(root->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
};
// @lc code=end

