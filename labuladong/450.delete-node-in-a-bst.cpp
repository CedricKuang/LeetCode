/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* getMin(TreeNode* root)
    {
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
        {
            if (root->left == nullptr)
                return root->right;
            if (root->right == nullptr)
                return root->left;
            
            TreeNode* min_node = getMin(root->right);
            root->right = deleteNode(root->right, min_node->val);
            min_node->left = root->left;
            min_node->right = root->right;
            root = min_node;
        }        
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
// @lc code=end

