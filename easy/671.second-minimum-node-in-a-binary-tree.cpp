/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> all_val;
    int findSecondMinimumValue(TreeNode* root) {
        get_all_vals(root);
        sort(all_val.begin(), all_val.end());
        for (int i = 0; i < all_val.size(); i++)
            if (all_val[i] > all_val[0])
                return all_val[i];
        
        return -1;
    }

    void get_all_vals(TreeNode* root) {
        if (root == nullptr)
            return;
        all_val.push_back(root->val);
        get_all_vals(root->left);
        get_all_vals(root->right);
        return;
    }

};
// @lc code=end

