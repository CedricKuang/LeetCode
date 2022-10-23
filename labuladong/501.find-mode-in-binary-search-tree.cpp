/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    unordered_map<int, int> vals;
    void get_vals(TreeNode* root)
    {
        if (root == nullptr)
            return;
        get_vals(root->left);
        vals[root->val]++;
        get_vals(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        get_vals(root);
        vector<int> ans;
        int max_freq = 0;
        for (auto it = vals.begin(); it != vals.end(); it++)
        {
            if (it->second == max_freq)
                ans.push_back(it->first);
            else if (it->second > max_freq)
            {
                max_freq = it->second;
                ans.clear();
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
// @lc code=end

