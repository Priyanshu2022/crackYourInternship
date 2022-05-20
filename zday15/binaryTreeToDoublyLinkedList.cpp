// binary tree to doubly linked list
// inorder
// left will act as previous and right as next
// maintain a previous and make the first node as head
// point root's left to prev and prev's right to root
void solve(Node* root,Node* &prev,Node* &head){ // pass both by reference
        if(root==NULL) return ;
        solve(root->left,prev,head);
        if(prev==NULL) head=root;
        else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        solve(root->right,prev,head);
    }
    Node * bToDLL(Node *root)
    {
        Node* prev=NULL;
        Node* head=NULL;
        solve(root,prev,head);
        return head;
    }