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
#include <cmath>
using namespace std;


class Solution {
public:
    vector<int> all_vals;
    int minDiffInBST(TreeNode* root) {
        get_all_vals(root);
        // sort(all_vals.begin(), all_vals.end());
        int min_diff = all_vals[1] - all_vals[0];
        for (int i = 1; i < all_vals.size() - 1; i++)
        {
            if (all_vals[i + 1] - all_vals[i] < min_diff)
                min_diff = all_vals[i + 1] - all_vals[i];
        }
        return min_diff;
    }

    void get_all_vals(TreeNode* root)
    {
        if (root == nullptr)
            return;
        
        get_all_vals(root->left);
        all_vals.push_back(root->val);
        get_all_vals(root->right);
    }


};
// @lc code=end

