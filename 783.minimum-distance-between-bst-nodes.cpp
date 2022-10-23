/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> vals;
    void get_vals(TreeNode* root)
    {
        if (root == nullptr)
            return;
        get_vals(root->left);
        vals.push_back(root->val);
        get_vals(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        get_vals(root);
        int diff = INT_MAX;
        for (int i = 1; i < vals.size(); i++)
        {
            diff = min(diff, vals[i] - vals[i - 1]);
        }
        return diff;
    }
};
// @lc code=end

