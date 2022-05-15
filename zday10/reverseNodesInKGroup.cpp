// reverse nodes in k groups
ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        
        ListNode* temp=head;
        for(int i=0;i<k;i++){
            if(!temp) return head;
            temp=temp->next;
        }
        
        int count=0;
        ListNode* next=NULL;
        ListNode* cur=head;
        ListNode* prev=NULL;
        while(cur!=NULL && count<k){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            count++;
        }
        if(cur!=NULL){
            head->next=reverseKGroup(cur,k);
        }
        return prev;
    }