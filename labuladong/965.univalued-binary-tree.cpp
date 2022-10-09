/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        if (root->left != nullptr && root->right != nullptr)
            return root->val == root->left->val && root->val == root->right->val && isUnivalTree(root->left) && isUnivalTree(root->right);
        else if (root->left != nullptr)
            return root->val == root->left->val && isUnivalTree(root->left) && isUnivalTree(root->right);
        else if (root->right != nullptr)
            return root->val == root->right->val && isUnivalTree(root->left) && isUnivalTree(root->right);
        else
            return true;
    }
};
// @lc code=end

