/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int res = 0;
    int rank = 0;
    void traverse(TreeNode* root, int k)
    {
        if (root == nullptr)
            return;
        traverse(root->left, k);
        rank++;
        if (rank == k)
        {
            res = root->val;
            return;
        }
        traverse(root->right, k);
    }
    int kthSmallest(TreeNode* root, int& k) {
        traverse(root, k);
        return res;
    }
};
// @lc code=end

