/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
#include <string>
using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == nullptr)
            return result;

        result = add_two_vectors(binaryTreePaths(root->left), binaryTreePaths(root->right));
    
        int root_val = root->val;
        if (result.empty())
        {
            result.insert(result.end(), to_string(root_val));
            return result;
        }

        string root_str = to_string(root_val) + "->";
        for (int i = 0; i < result.size(); i++)
            result[i] = root_str + result[i];
        return result;
    }

    vector<string> add_two_vectors(vector<string> a, vector<string> b)
    {
        for (int i = 0; i < b.size(); i++)
            a.insert(a.end(), b[i]);
        return a;
    }
};
// @lc code=end

