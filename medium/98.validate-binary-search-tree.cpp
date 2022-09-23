/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    void in_order(TreeNode* root, vector<int>& ans)
    {
        if (root == nullptr)
            return;
        in_order(root->left, ans);
        ans.push_back(root->val);
        in_order(root->right, ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        in_order(root, ans);
        for (int i = 1; i < ans.size(); i++)
        {
            if (ans[i] <= ans[i - 1])
                return false;
        }
        return true;
    }
};
// @lc code=end

