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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next_node = curr->next; // 1. Store next node
            curr->next = prev;                // 2. Reverse pointer direction
            prev = curr;                      // 3. Move prev forward
            curr = next_node;                 // 4. Move curr forward
        }

        return prev; // prev is the new head of the reversed list
    }
};
