/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int max_dia = 0;
    int helper(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int left_height = helper(root->left);
        int right_height = helper(root->right);
        if (max_dia < left_height + right_height)
            max_dia = left_height + right_height;
        return 1 + max(left_height, right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return max_dia;
    }
};
// @lc code=end

