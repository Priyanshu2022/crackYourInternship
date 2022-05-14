ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        while(head && head->val==val){
            head=head->next;
        }
        ListNode*cur=head;
        while(cur){
            while(cur->next && cur->next && cur->next->val==val){
                cur->next=cur->next->next;
            }
            cur=cur->next;
        }
        return head;
    }