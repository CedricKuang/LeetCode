/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
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
#include <cmath>
using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num_nodes = 0;
        int ans = 0;
        ListNode* temp = head;
        while (temp != nullptr)
        {
            num_nodes++;
            temp = temp->next;
        }

        temp = head;
        while (num_nodes > 0)
        {
            if (temp->val == 1)
                ans += pow(2, num_nodes - 1);
            num_nodes--;
            temp = temp->next;
        }
        return ans;
    }
};
// @lc code=end

