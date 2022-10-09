/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* dummy = new ListNode;
        ListNode* p3 = dummy;
        int sum = 0, carry = 0;
        while (p1 != nullptr || p2 != nullptr)
        {
            if (p1 != nullptr)
            {
                sum += p1->val;
                p1 = p1->next;
            }

            if (p2 != nullptr)
            {
                sum += p2->val;
                p2 = p2->next;
            }

            sum += carry;
            ListNode* new_node = new ListNode(sum % 10);
            p3->next = new_node;
            p3 = p3->next;
            carry = sum / 10;
            sum = 0;
        }
        if (carry != 0)
        {
            ListNode* new_node = new ListNode(carry);
            p3->next = new_node;
        }

        return dummy->next;
    }
};
// @lc code=end

