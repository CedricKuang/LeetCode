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
    TreeNode* buildTreeHelper(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, 
    int in_start, int in_end)
    {
        if (pre_start > pre_end || in_start > in_end)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int index = valtoindex[preorder[pre_start]];
        int left_size = index - in_start;
        root->left = buildTreeHelper(preorder, pre_start + 1, pre_start + left_size, inorder, in_start, index - 1);
        root->right = buildTreeHelper(preorder, pre_start + left_size + 1, pre_end, inorder, index + 1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            valtoindex[inorder[i]] = i;
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

