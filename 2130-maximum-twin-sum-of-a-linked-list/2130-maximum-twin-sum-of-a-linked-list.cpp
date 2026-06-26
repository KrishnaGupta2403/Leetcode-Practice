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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        //mid
        while(fast!=NULL &&  fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // revrse 
        ListNode* mid=slow;
        ListNode*  prev=NULL;
        ListNode* nextnode=NULL;
        while(mid!=NULL){
            nextnode=mid->next;
            mid->next=prev;
            prev=mid;
            mid=nextnode;
        }

        ListNode*  curr=head;
        int ans=INT_MIN;
        while(prev!=NULL){
            ans=max(ans, curr->val+prev->val);
            prev=prev->next;
            curr=curr->next;
        }
        return ans;
    }
};