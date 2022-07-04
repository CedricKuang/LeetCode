/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        int num = 0;
        ListNode* temp = head;
        while (temp != nullptr)
        {
            num++;
            temp = temp->next;
        }
        temp = head;
        int i = 0;
        while (i != (num/2))
        {
            temp = temp->next;
            i++;
        }
        return temp;
    }
};
// @lc code=end

