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
    ListNode* ans;
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* ans;
        ListNode* itr1 = l1; ListNode* itr2 = l2;

        if (itr1->val > itr2->val) {
            ans = itr2;
            ListNode* itr2 = l2->next;
            ans->next = mergeTwoLists(itr1, itr2);
        }
        else {
            ans = itr1;
            ListNode* itr1 = l1->next;
            ans->next = mergeTwoLists(itr1, itr2);

        }

        return ans;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k < 1)return NULL;
        for (int i = 0; i < k - 1; i++) {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin(), lists.begin() + 2);
        }
        return lists.front();
    }

};