// Predecessor and Successor 
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node* temp=root;
    while(temp){
        if(temp->key>key){
            suc=temp;
            temp=temp->left;
        }
        else temp=temp->right;
    }
    temp=root;
    while(temp){
        if(temp->key<key){
            pre=temp;
            temp=temp->right;
        }
        else temp=temp->left;
    }
}