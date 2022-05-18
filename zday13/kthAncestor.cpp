// kth ancestor of a node
// root's data is node return root
// call in left and right
// if both null return null
// if one of them is not null
// decrement k , k==0 return root else return the one which is not null
Node* solve(Node* root,int &k ,int node){
    if(root==NULL) return NULL;
    if(root->data==node) return root;
    Node* left= solve(root->left,k,node);
    Node* right= solve(root->right,k,node);
    if(left==NULL && right!=NULL){
        k--;
        if(k==0) return root;
        else return right;
    }
    if(right==NULL && left!=NULL){
        k--;
        if(k==0) return root;
        else return left;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans=solve(root,k,node);
    if(ans==NULL || ans->data==node) return -1;
    else
    return ans->data;
}