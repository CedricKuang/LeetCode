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
    unordered_map<int, int> table;

    TreeNode* build_tree(vector<int>& preorder, int pre_start, int pre_end, 
    vector<int>& inorder, int in_start, int in_end)
    {
        if (pre_start > pre_end || in_start > in_end)
            return nullptr;
        TreeNode* new_node = new TreeNode(preorder[pre_start]);
        int root_index = table[new_node->val];
        int left_length = root_index - in_start;
        new_node->left = build_tree(preorder, pre_start + 1, pre_start + left_length, 
        inorder, in_start, root_index - 1);
        new_node->right = build_tree(preorder, pre_start + left_length + 1, pre_end, 
        inorder, root_index + 1, in_end);
        return new_node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            table[inorder[i]] = i;
        return build_tree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

