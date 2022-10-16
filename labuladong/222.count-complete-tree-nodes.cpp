/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        TreeNode* left = root;
        TreeNode* right = root;
        int hl = 0, hr = 0;
        while (left != nullptr)
        {
            left = left->left;
            hl++;
        }
        while (right != nullptr)
        {
            right = right->right;
            hr++;
        }

        if (hl == hr)
        {
            return (int)pow(2, hl) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
        

    }
};
// @lc code=end

