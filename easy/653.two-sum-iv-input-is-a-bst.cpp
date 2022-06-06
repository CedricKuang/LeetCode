/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    bool findTarget(TreeNode* root, int k) {
        all_vals(root);
        for (int i = 0; i < vals.size() - 1; i++)
        {
            for (int m = (i + 1); m < vals.size(); m++)
                if (vals[i] + vals[m] == k)
                    return true;
        }
        return false;
    }

    void all_vals(TreeNode* root) {
        if (root == nullptr)
            return;
        vals.push_back(root->val);
        all_vals(root->left);
        all_vals(root->right);
        return;
    }
};
// @lc code=end

