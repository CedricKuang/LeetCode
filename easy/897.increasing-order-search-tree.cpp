/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.*/

//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };
 
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> all_vals;
    void get_all_vals(TreeNode* root)
    {
        if (root == nullptr)
            return;
        
        get_all_vals(root->left);
        all_vals.push_back(root->val);
        get_all_vals(root->right);
        return;
    }

    TreeNode* increasingBST(TreeNode* root) {
        get_all_vals(root);
        TreeNode* new_root = new TreeNode(all_vals[0]);
        TreeNode* temp_pointer = new_root;
        for (int i = 1; i < all_vals.size(); i++)
        {
            TreeNode* temp = new TreeNode(all_vals[i]);
            temp_pointer->right = temp;
            temp_pointer = temp_pointer->right;
        }
        temp_pointer = nullptr;
        return new_root;
    }
};
// @lc code=end

