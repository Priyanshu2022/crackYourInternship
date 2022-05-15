// segregate even and odd
Node* divide(int N, Node *head){
        Node* even=new Node(-1);
        Node* evenP=even;
        Node* odd=new Node(-1);
        Node* oddP=odd;
        while(head){
            if((head->data)&1){
                oddP->next=head;
                oddP=head;
            }
            else{
                evenP->next=head;
                evenP=head;
            }
            head=head->next;
        }
        oddP->next=NULL;
        if(odd->next){
            evenP->next=odd->next;
        }
        return even->next;
    }