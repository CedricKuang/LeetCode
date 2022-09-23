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
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> inorder;
    void in_order(TreeNode* root)
    {
        if (root == nullptr)
            return;
        in_order(root->left);
        inorder.push_back(root->val);
        in_order(root->right);

    }

    void in_order_stack(TreeNode* root)
    {
        stack<TreeNode*> my_stack;
        TreeNode* curr = root;

        while (curr != nullptr || !my_stack.empty())
        {
            while (curr != nullptr)
            {
                my_stack.push(curr);
                curr = curr->left;
            }

            curr = my_stack.top();
            my_stack.pop();
            inorder.push_back(curr->val);
            curr = curr->right;
        }
    }

    bool in_order_no_vector(TreeNode* root, int upper, int lower)
    {
        if (root == nullptr)
            return true;
        if (upper && root->val >= upper)
            return false;
        if (lower && root->val <= lower)
            return false;
        
        return in_order_no_vector(root->left, lower, root->val) && in_order_no_vector(root->right, root->val, upper);
        
    }

    bool isValidBST(TreeNode* root) {
        in_order(root);
        for (int i = 1; i < inorder.size(); i++)
        {
            if (inorder[i] < inorder[i - 1])
                return false;
        }
        return true;
    }
};
// @lc code=end

