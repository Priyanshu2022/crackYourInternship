// find mid 
// separate two list's
// sort by recursion
// merge and return 
ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        if(left==NULL) return right;
        if(right==NULL) return left;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(left && right){
            if(left->val>right->val){
                temp->next=right;
                right=right->next;
                temp=temp->next;
            }
            else{
                temp->next=left;
                left=left->next;
                temp=temp->next;
            }
        }
        while(left){
            temp->next=left;
            left=left->next;
            temp=temp->next;
        }
        while(right){
            temp->next=right;
            right=right->next;
            temp=temp->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=findMid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }