/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> my_queue;
        my_queue.push(root);
        while (!my_queue.empty())
        {
            int size = my_queue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* front_node = my_queue.front();
                my_queue.pop();
                if (front_node->left != nullptr)
                    my_queue.push(front_node->left);
                if (front_node->right != nullptr)
                    my_queue.push(front_node->right);
                
                if (i == size - 1)
                    ans.push_back(front_node->val);
            }
        }
        return ans;
    }
};
// @lc code=end

