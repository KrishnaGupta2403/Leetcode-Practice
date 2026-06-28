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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num=0,node;
        ListNode *ptr=head;
        if(!head)
        return nullptr;
        while(ptr)
        {
            ptr=ptr->next;
            num++;

        }
        node=num-n;
        if(node==0)
        {
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode *curr=head,*prev=NULL;
        for(int i=0;i<node;i++)
        {
            prev=curr;
            curr = curr->next;
        }
        ListNode* temp=curr;
        prev->next=curr->next;
        delete temp;
        return head;
       
    
    }
};