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
        bool left_correct = (root->left == nullptr ||
                (root->val == root->left->val && isUnivalTree(root->left)));
        bool right_correct = (root->right == nullptr ||
                (root->val == root->right->val && isUnivalTree(root->right)));
        return left_correct && right_correct;
    }
};
// @lc code=end

