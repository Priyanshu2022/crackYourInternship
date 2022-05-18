// maximum sum of non adjacent elements
// at every node there are two options we can take it or leave it
pair<int,int> solve(Node* root){
        if(root==NULL){
            pair<int,int> temp={0,0};
            return temp;
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        pair<int,int> ans;
        ans.first=root->data+left.second+right.second;// including first, so taking excluding of left and right
        ans.second=max(left.first,left.second)+max(right.first,right.second);
        return ans;
    }
    int getMaxSum(Node *root) 
    {
        // max sum when includeing current , excluding
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
    }