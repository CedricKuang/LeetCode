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
    int ans = 0;
    int find_depth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int left_depth = find_depth(root->left);
        int right_depth = find_depth(root->right);
        ans = max(left_depth + right_depth, ans);
        return max(1 + left_depth, 1 + right_depth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        find_depth(root);
        return ans;
    }
};
// @lc code=end

