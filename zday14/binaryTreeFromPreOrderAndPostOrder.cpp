TreeNode* solve(vector<int> &pre,map<int,int> &postOrderMap,int &preIndex,int postStart,int postEnd){
        if(postStart>postEnd) return NULL;
        TreeNode* node =new TreeNode(pre[preIndex]);
        preIndex++;
        if(postStart==postEnd) return node;
        int postIndex=postOrderMap[pre[preIndex]];
        node->left=solve(pre,postOrderMap,preIndex,postStart,postIndex);
        node->right=solve(pre,postOrderMap,preIndex,postIndex+1,postEnd-1);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        map<int,int> postOrderMap;
        for(int i=0;i<post.size();i++) postOrderMap[post[i]]=i;
        int preIndex=0;
        return solve(pre,postOrderMap,preIndex,0,post.size()-1);
    }