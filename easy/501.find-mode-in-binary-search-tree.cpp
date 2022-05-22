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
using namespace std;

class Solution {
public:
    int maxTillNow = -1000000, curr = -1000000, prev = -1000000;
    
    void inOrder(TreeNode* root, vector<int> &ans) {        
        if(root == nullptr)
            return;
        inOrder(root->left, ans);
		 
		// the last visited element will be inOrder predecessor so if it occurs more than once, it has to be same here because it is a BST
        if(root->val == prev)
            curr++;
        
        else if(prev != root->val)
            curr = 1;
                
        if(curr>maxTillNow) {
            ans.clear();
            ans.push_back(root->val);
            maxTillNow = curr;
        } 
        else if(curr == maxTillNow)
            ans.push_back(root->val);
        
        prev = root->val;
        inOrder(root->right, ans);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }
};
// @lc code=end

