// there are two methods
// first to count 0 , 1 and 2 then replace
// second if you dont want to replace
// create 6 nodes
// and attach 0 , 1 , 2

void insertAtTail(Node* &tail,Node* cur){ // pass by reference
        tail->next=cur;
        tail=cur; // pointing tail ahead
    }
    Node* segregate(Node *head) {
        
        Node* zeroHead=new Node(-1);
        Node* zeroTail=zeroHead;
        Node* oneHead=new Node(-1);
        Node* oneTail=oneHead;
        Node* twoHead=new Node(-1);
        Node* twoTail=twoHead;
        
        Node* cur=head;
        while(cur){
            if(cur->data==0){
                insertAtTail(zeroTail,cur);
            }
            else if(cur->data==1){
                insertAtTail(oneTail,cur);
            }
            else if(cur->data==2){
                insertAtTail(twoTail,cur);
            }
            cur=cur->next;
        }
        
        if(oneHead->next==NULL){
            zeroTail->next=twoHead->next;
        }
        else zeroTail->next=oneHead->next;
        
        oneTail->next=twoHead->next;
        twoTail->next=NULL;
        head=zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
        
    }