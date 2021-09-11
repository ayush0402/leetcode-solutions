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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        for (ListNode* itr = head; itr != NULL; n++, itr = itr->next);
        ListNode* temp = new ListNode(0);
        temp->next = head;
        for (ListNode* prev = temp, * tail = head; n >= k; n -= k) {
            for (int i = 1; i < k; i++) {
                ListNode* next = tail->next->next;
                tail->next->next = prev->next;
                prev->next = tail->next;
                tail->next = next;
            }
            prev = tail;
            tail = tail->next;
        }
        return temp->next;

    }
};