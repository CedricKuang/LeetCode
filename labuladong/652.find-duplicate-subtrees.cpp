/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
#include <string>
using namespace std;

class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<string, int> sub_to_freq;
    string traverse(TreeNode* root)
    {
        if (root == nullptr)
            return "#";
        
        string left = traverse(root->left);
        string right = traverse(root->right);

        string sub = left + "," + right + "," + to_string(root->val);

        if (sub_to_freq[sub] == 1)
        {
            ans.push_back(root);
        }

        sub_to_freq[sub]++;
        return sub;
    }   
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return ans;        
    }
};
// @lc code=end

