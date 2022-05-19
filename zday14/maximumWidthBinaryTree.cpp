// maximum width binary tree
// find maximum width between any two existing nodes (in a level)
// if we mark the index , then the task is to subtract first and last and add 1
// children of i -> 2*i+1,2*i+2
// queue will be of pair of node , index
// subtracting the minimum of every level (first element) with index , to store in int
int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long int mini=q.front().second;
             int first,last;
            for(int i=0;i<size;i++){
                long long int cur_index=q.front().second-mini;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=cur_index;
                if(i==size-1) last=cur_index;
                if(node->left){
                    q.push({node->left,cur_index*2+1});
                }
                if(node->right){
                    q.push({node->right,cur_index*2+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }