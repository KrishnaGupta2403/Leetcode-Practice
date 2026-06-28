/**
 * Definition for singly-linked list.
 * struct ListNode {----
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateKtimes(ListNode* head, int k) {
        if(head == NULL or head->next == NULL) return head;
        if(k == 0) return head;
        ListNode *prev = head, *curr = head;

        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        curr->next = head;
        head = curr;
        k--;
        return rotateKtimes(head, k);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int t = 0;
        while(temp != NULL){
            temp = temp->next;
            t++;
        }
        if(k > t and t!=0){
            k = k%((k/(t))*t);
        }
        return rotateKtimes(head, k);
    }
};