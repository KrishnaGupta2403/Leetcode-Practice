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
    ListNode* sortList(ListNode* head) {
         if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        
        while (fast != NULL && fast->next != NULL) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = NULL; 

       ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        
        ListNode* ans = merge(left, right);
        return ans;

    }
    ListNode* merge(ListNode*left,ListNode*right)
    {
       ListNode* ans = new ListNode(0); 
        ListNode* ptr = ans;

        while (left != NULL && right != NULL) {
            if (left->val <= right->val) {
                ptr->next = left;
                left = left->next;
            } else {
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }

       if(left != NULL) {
            ptr->next = left;
            left = left->next;
        }

       if(right != NULL) {
            ptr->next = right;
            right = right->next;
        }

        return ans->next; 
    }
};