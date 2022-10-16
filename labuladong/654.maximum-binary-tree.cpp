/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* helper(vector<int>& nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int max_num = INT_MIN;
        int max_index = -1;
        for (int i = left; i <= right; i++)
        {
            if (nums[i] > max_num)
            {
                max_num = nums[i];
                max_index = i;
            }
        }
        TreeNode* root = new TreeNode(max_num);
        root->left = helper(nums, left, max_index - 1);
        root->right = helper(nums, max_index + 1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

