/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> valtoindex;
    TreeNode* buildTreeHelper(vector<int>& postorder, int post_start, int post_end, vector<int>& inorder, 
    int in_start, int in_end)
    {
        if (post_start > post_end || in_start > in_end)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[post_end]);
        int index = valtoindex[postorder[post_end]];
        int left_size = index - in_start;
        root->left = buildTreeHelper(postorder, post_start, post_start + left_size - 1, inorder, in_start, index - 1);
        root->right = buildTreeHelper(postorder, post_start + left_size, post_end - 1, inorder, index + 1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            valtoindex[inorder[i]] = i;
        return buildTreeHelper(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

