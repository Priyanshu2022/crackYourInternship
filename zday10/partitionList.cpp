// patition list
// separate number less than x and greater than x
// we make dummy nodes so we do not need to handle if head's position is changing
ListNode* partition(ListNode* head, int x) {
        ListNode* less=new ListNode(-1);
        ListNode* curLess=less;
        ListNode* greater=new ListNode(-1);
        ListNode* curGreater=greater;
        while(head){
            if((head->val)<x){
                curLess->next=head;
                curLess=curLess->next;
            }
            else{
                curGreater->next=head;
                curGreater=curGreater->next;
            }
            head=head->next;
        }
        curGreater->next=NULL;
        if(greater->next)
        curLess->next=greater->next;
        return less->next;;
    }