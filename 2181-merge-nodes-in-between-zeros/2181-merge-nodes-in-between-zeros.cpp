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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans= new ListNode(-1);
        ListNode* curr=head->next;
        ListNode* temp=ans;
        while(curr){
            int sum=0;
            while(curr->val!=0 && curr){
                sum+=curr->val;
                curr=curr->next;
            }
            curr=curr->next;
            temp->next=new ListNode(sum);
            temp=temp->next;
        }
        return ans->next;
    }
};