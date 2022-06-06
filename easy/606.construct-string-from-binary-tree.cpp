/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
#include <string>
using namespace std;

class Solution {
     void buildStr(TreeNode* node, ostringstream& out) {
        if (!node) return;
        out << node->val;
        if (node->left || node->right) {
            out << "(";
            buildStr(node->left, out);
            out << ")";
            
            if (node->right) {
                out << "(";
                buildStr(node->right, out);
                out << ")";
            }
        }
    }
    
public:
    string tree2str(TreeNode* t) {
        ostringstream out;
        buildStr(t, out);
        return out.str();
    }
};
// @lc code=end

