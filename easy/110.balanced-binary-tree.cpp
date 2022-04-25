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
 * 
 */
#include <iostream>
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int diff = TreeDepth(root->left) - TreeDepth(root->right);
        if (diff > 1 || diff < -1)
            return false;
        else 
            return isBalanced(root->left) && isBalanced(root->right);
    }

    int TreeDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int left_depth = TreeDepth(root->left);
        int right_depth = TreeDepth(root->right);
        if (left_depth >= right_depth)
            return (left_depth + 1);
        else
            return (right_depth + 1);
    }
};
// @lc code=end

