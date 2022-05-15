// reorder list 
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// find mid
// break into two list (2nd one should be reversed)
// then attach
ListNode* reverseList(ListNode* head) {
        ListNode* newHead=NULL;
        while(head){
            ListNode* temp=head->next;
            head->next=newHead;
            newHead=head;
            head=temp;
        }
        return newHead;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* first=head;
        ListNode* second=reverseList(slow->next);
        slow->next=NULL;
        while(second){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }