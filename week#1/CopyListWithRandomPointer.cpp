/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node *temp = head;
        unordered_map<Node*, Node*> mep;
        Node* head2 = new Node(head->val);
        Node *curr = head2;
        mep[temp] = head2;
        temp = temp->next;

        while (temp != NULL) {
            curr->next = new Node(temp->val);
            mep[temp] = curr->next;
            temp = temp->next;
            curr = curr->next;
        }
        temp = head;
        curr = head2;

        while (temp != NULL) {
            if (temp->random) {
                curr->random = mep[temp->random];
            }
            curr = curr->next;
            temp = temp->next;
        }
        return head2;
    }
};