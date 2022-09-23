/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* build(vector<int>& preorder, int prestart, int preend, vector<int>& inorder,
    int instart, int inend)
    {
        if (prestart > preend)
            return nullptr;
        int root_val = preorder[prestart];
        int index = valtoindex[root_val];
        int left_size = index - instart;

        TreeNode* root = new TreeNode(root_val);
        root->left = build(preorder, prestart + 1, prestart + left_size, inorder, instart, index - 1);
        root->right = build(preorder, prestart + left_size + 1, preend, inorder, index + 1, inend);
        return root;
    }   

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            valtoindex[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

