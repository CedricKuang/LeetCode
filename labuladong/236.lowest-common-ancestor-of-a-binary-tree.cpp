/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        
        if (root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode* left_ans = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_ans = lowestCommonAncestor(root->right, p, q);

        if (left_ans == nullptr)
            return right_ans;
        else if (right_ans == nullptr)
            return left_ans;
        else    
            return root;
    }
};
// @lc code=end

