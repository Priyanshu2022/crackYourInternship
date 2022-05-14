// assume the first node is the last node
// when we go to next node then we assume it as to be the last
// and multiply the previous answer by 2
int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head){
            ans*=2;
            ans+=head->val;// head->val*2^0
            head=head->next;
        }
        return ans;
    }