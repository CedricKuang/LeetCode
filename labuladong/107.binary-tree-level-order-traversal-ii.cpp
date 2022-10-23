/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void helper(TreeNode* root)
    {
        if (root == nullptr)
            return;
        queue<TreeNode*> my_q;
        my_q.push(root);
        while (!my_q.empty())
        {
            int width = my_q.size();
            vector<int> temp;
            for (int i = 0; i < width; i++)
            {
                TreeNode* front = my_q.front();
                my_q.pop();
                temp.push_back(front->val);
                if (front->left != nullptr)
                    my_q.push(front->left);
                if (front->right != nullptr)
                    my_q.push(front->right);
            }
            ans.push_back(temp);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        helper(root);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

