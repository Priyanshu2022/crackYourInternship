// reverse from left to right
// two methods one is the simple one
// other one is this
ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        dummy->next=head;
        for(int i=0;i<left-1;i++){
            prev=prev->next;
        }
        ListNode* tail=prev->next;
        for(int i=0;i<right-left;i++){
            ListNode* temp=prev->next;
            prev->next=tail->next;
            tail->next=prev->next->next;
            prev->next->next=temp;
        }
        return dummy->next;
    }