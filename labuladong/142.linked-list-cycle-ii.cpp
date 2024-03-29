/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        ListNode* fast = head; 
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                break;
        }

        if (fast == nullptr || fast->next == nullptr)
            return nullptr;
        
        slow = head;
        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
// @lc code=end

