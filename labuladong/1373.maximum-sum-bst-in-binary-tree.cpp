/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
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
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<TreeNode*, int> max_vals;
    unordered_map<TreeNode*, int> min_vals;
    int ans = 0;
    int helper(TreeNode* root)
    {
        if (root == nullptr)
            return INT_MIN;
        int left_ans = helper(root->left);
        int right_ans = helper(root->right);
        // cout << left_ans << " " << right_ans << endl;
        if (left_ans == INT_MIN && right_ans == INT_MIN)
        {
            max_vals[root] = root->val;
            min_vals[root] = root->val;
            ans = max(root->val, ans);
            return root->val;
        }
        else if (left_ans == INT_MIN && right_ans != INT_MAX)
        {
            if (root->val < min_vals[root->right])
            {
                max_vals[root] = max_vals[root->right];
                min_vals[root] = root->val;
                ans = max(ans, root->val + right_ans);
                return root->val + right_ans;
            }
            else
            {
                return INT_MAX;
            }
        }
        else if (left_ans != INT_MAX && right_ans == INT_MIN)
        {
            if (root->val > max_vals[root->left])
            {
                max_vals[root] = root->val;
                min_vals[root] = min_vals[root->left];
                ans = max(ans, root->val + left_ans);
                return root->val + left_ans;
            }
            else
            {
                return INT_MAX;
            }
        }
        else if (left_ans == INT_MAX || right_ans == INT_MAX)
            return INT_MAX;
        else
        {
            if (root->val < min_vals[root->right] && root->val > max_vals[root->left])
            {
                min_vals[root] = min_vals[root->left];
                max_vals[root] = max_vals[root->right];
                ans = max(ans, root->val + left_ans + right_ans);
                return root->val + left_ans + right_ans;
            }
            else
                return INT_MAX;
        }

    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};
// @lc code=end

