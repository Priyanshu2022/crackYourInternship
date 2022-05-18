// check if bst had dead end (no further nodes can be added)
// if min and max becomes true , return true (means there is a dead end)
bool solve(Node* root,int min,int max)
{
    if(root==NULL ) return false;
    if(min==max) return true;
    return solve(root->left,min,root->data-1) || solve(root->right,root->data+1,max);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    return solve(root,1,INT_MAX);
}