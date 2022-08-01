/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* prev = nullptr;
        ListNode* nex = head->next;
        for(;;)
        {
            if (prev == nullptr)
            {
                head->next = nex->next;
                nex->next = head;
                head = nex;
            }
            else
            {
                prev->next->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
            }
            prev = nex->next;
            nex = nex->next->next;
            if (nex == nullptr)
                break;
            nex = nex->next;
            if (nex == nullptr)
                break;
            
        }
        return head;
    }
};
// @lc code=end

