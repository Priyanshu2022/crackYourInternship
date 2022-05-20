// binary tree maximum path
// any path where nodes can come in the sequence at most 1
// we are returning the maximum sum of either the left or right part
// and at current node we are finding maximum of left+right+root->valid
int solve(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        int left=max(0,solve(root->left,ans));
        int right=max(0,solve(root->right,ans));
        ans=max(ans,left+right+root->val);
        return root->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }