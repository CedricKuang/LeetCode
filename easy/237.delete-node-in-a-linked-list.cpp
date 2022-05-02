/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // this question shall be deleted from the leetcode question set
        // I personally don't consider the following answer as "delete a node"
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
// @lc code=end

