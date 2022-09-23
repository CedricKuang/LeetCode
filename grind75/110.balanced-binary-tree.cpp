/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int get_height(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int left_height = get_height(root->left);
        int right_height = get_height(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int left_height = get_height(root->left);
        int right_height = get_height(root->right);
        if (abs(left_height - right_height) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end

