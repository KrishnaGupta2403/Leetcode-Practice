class Solution {
public:

    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;

        while(head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;

        while(true){

            // Find kth node
            ListNode* kth = prevGroup;

            for(int i=0;i<k && kth;i++){
                kth = kth->next;
            }

            if(!kth)
                break;

            ListNode* groupStart = prevGroup->next;
            ListNode* nextGroup = kth->next;

            // Disconnect group
            kth->next = nullptr;

            // Reverse group
            ListNode* newHead = reverse(groupStart);

            // Connect
            prevGroup->next = newHead;
            groupStart->next = nextGroup;

            // Move prevGroup
            prevGroup = groupStart;
        }

        return dummy.next;
    }
};