class BSTIterator{
    stack<TreeNode*> st;
    bool reverse=true;
public:
    BSTIterator(TreeNode* root,bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        TreeNode* temp=st.top();
        st.pop();
        if(reverse) pushAll(temp->left);
        else pushAll(temp->right);
        return temp->val;
    }
    void pushAll(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            if(reverse){
                node=node->right;
            }
            else node=node->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j>k) j=r.next();
            else if(i+j<k) i=l.next();
            else return true;
        }
        return false;
    }
};