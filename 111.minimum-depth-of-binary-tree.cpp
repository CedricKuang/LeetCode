/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);
        if (root->left == nullptr && root->right != nullptr)
            return 1 + right_depth;
        else if (root->left != nullptr && root->right == nullptr)
            return 1 + left_depth;
        return 1 + min(left_depth, right_depth);
    }
};
// @lc code=end

