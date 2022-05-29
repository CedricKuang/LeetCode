/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
#include <cmath>

class Solution {
public:
    int findTilt(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        return abs(nodesum(root->left) - nodesum(root->right)) 
            + findTilt(root->left) + findTilt(root->right);
    }

    int nodesum(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return root->val + nodesum(root->left) + nodesum(root->right);
    }
};
// @lc code=end

