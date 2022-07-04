/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf_a;
        vector<int> leaf_b;
        get_all_leaves(root1, leaf_a);
        get_all_leaves(root2, leaf_b);
        if (leaf_a.size() != leaf_b.size())
            return false;
        
        for (int i = 0; i < leaf_a.size(); i++)
        {
            if (leaf_a[i] != leaf_b[i])
                return false;
        }
        return true;
    }

    void get_all_leaves(TreeNode* root, vector<int>& leaf) 
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            leaf.push_back(root->val);
        }

        if (root->left != nullptr)
        {
            get_all_leaves(root->left, leaf);
        }
        
        if (root->right != nullptr)
        {
            get_all_leaves(root->right, leaf);
        }
            
    }
};
// @lc code=end

