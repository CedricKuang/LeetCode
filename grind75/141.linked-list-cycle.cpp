/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;
        ListNode* first = head;
        ListNode* second = head->next;
        while (first != nullptr && second != nullptr)
        {
            if (first == second)
                return true;
            first = first->next;
            second = second->next;
            if (second == nullptr)
                return false;
            second = second->next;
        }
        return false;
        
    }
};
// @lc code=end

