/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
class Solution {
public:
    int sum = 0;
    void traverse(TreeNode* root)
    {
        if (root == nullptr)
            return;
        traverse(root->right);
        root->val = root->val + sum;
        sum = root->val;
        traverse(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
};
// @lc code=end

