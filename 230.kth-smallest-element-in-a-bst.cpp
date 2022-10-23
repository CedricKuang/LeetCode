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
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nums;
    void get_element(TreeNode* root)
    {
        if (root == nullptr)
            return;
        get_element(root->left);
        nums.push_back(root->val);
        get_element(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        get_element(root);
        return nums[k - 1];
    }
};
// @lc code=end

