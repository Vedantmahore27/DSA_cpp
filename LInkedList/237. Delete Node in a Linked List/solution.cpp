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
        ListNode *curr = node;
        curr->val=curr->next->val;
        curr->next=curr->next->next;
    }
};
//or har node ke age ki value copy karo last me delete kar dena O(N)
