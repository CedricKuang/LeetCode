/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
    int find_depth(TreeNode* root, int x)
    {
        if (root == nullptr)
            return -1;
        int dist = -1;
        if (x == root->val || ((dist = find_depth(root->left, x)) >= 0) || ((dist = find_depth(root->right, x)) >= 0))
            return dist + 1;
        return dist; 
    }

    bool is_common_parent(TreeNode* root, int x, int y)
    {
        if (root->left == nullptr && root->right == nullptr)
            return false;
        
        if (root->left == nullptr)
            return is_common_parent(root->right, x, y);
        
        if (root->right == nullptr)
            return is_common_parent(root->left, x, y);
        
        if ((root->left->val == x || root->right->val == x) && (root->left->val == y || root->right->val == y))
            return true;
        
        return is_common_parent(root->left, x, y) || is_common_parent(root->right, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int x_depth = find_depth(root, x);
        int y_depth = find_depth(root, y);
        if (x_depth == y_depth && !is_common_parent(root, x, y))
            return true;
        return false;
    }
};
// @lc code=end

