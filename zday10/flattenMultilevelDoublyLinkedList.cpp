// flatten a multilevel doubly linked list
// recursive function will return last node
Node* flatten_rec(Node* head){
        Node* cur=head;
        Node* last=head;
        while(cur){
            Node* child=cur->child;
            Node* next=cur->next;
            if(child){
                Node* tail=flatten_rec(cur->child);
                tail->next=next;
                if(next) next->prev=tail;
                cur->next=child;
                child->prev=cur;
                cur->child=NULL;
                cur=tail;
            }
            else cur=next;
            if(cur) last=cur;
        }
        return last;
    }
    Node* flatten(Node* head) {
        if(head) flatten_rec(head);
        return head;
    }