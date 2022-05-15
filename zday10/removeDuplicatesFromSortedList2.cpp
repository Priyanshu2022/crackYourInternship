// remove all duplicates
// only distincts node's should be left
// make prev node , start with dummy
ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* prev=dummy;
        while(head){
            if(head->next && head->val==head->next->val){
                while(head->next && head->val==head->next->val){
                    head=head->next;
                }
                prev->next=head->next;
            }
            else prev=prev->next;
            head=head->next;
        }
        return dummy->next;
    }