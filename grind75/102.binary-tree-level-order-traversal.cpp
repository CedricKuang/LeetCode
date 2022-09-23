/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty())
        {
            vector<int> temp;
            int sz = q1.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode* front = q1.front();
                q1.pop();
                temp.push_back(front->val);
                if (front->left != nullptr)
                    q1.push(front->left);
                if (front->right != nullptr)
                    q1.push(front->right);
            }
            if (!temp.empty())
                ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

