// two nodes are swapped in the bst 
// recover the corrrect bst
// maintain prev,first,middle(second),last pointers
// inorder gives sorted elements
// after calling left recursion
// check if prev exists and prev->val>root->val (wrong order)
// then check if it's the first time wrong order is yes make first=prev and middle=root other  wise
// last =root
// if last is not null , swap last  and first (inorder gives sorted order , only swapping of first and last can maintain the right order)
// other wise swap first and middle
class Solution {
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
public:
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev){
            if(prev->val>root->val){
                if(first==NULL){
                    first=prev;
                    middle=root;
                }
                else{
                    last=root;
                }
            }
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev=NULL;
        first=NULL;
        middle=NULL;
        last=NULL;
        inorder(root);
        if(last){
            swap(first->val,last->val);
        }
        else swap(first->val,middle->val);
    }
};