/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    struct DereferenceCompareNode : public std::binary_function<ListNode*, ListNode*, bool>
    {
        bool operator()(const ListNode* lhs, const ListNode* rhs) const
        {
            return lhs->val > rhs->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, DereferenceCompareNode> pq;
        ListNode* dummy = new ListNode;
        ListNode* p = dummy;

        for (ListNode* node : lists)
        {
            if (node != nullptr)
                pq.push(node);
        }
            

        while (!pq.empty())
        {
            ListNode* temp = pq.top();
            pq.pop();
            p->next = temp;
            if (temp->next != nullptr)
                pq.push(temp->next);
            p = p->next;
        }
        return dummy->next;
        
    }
};
// @lc code=end

