// minimum distance between any two nodes of a binary tree
// find the lca first, then find distance of the two nodes from lca
Node* lowestCommonAncestor(Node* root, int p, int q) {
        if(root==NULL) return NULL;
        if(root->data==p || root->data==q) return root;
        Node* left=lowestCommonAncestor(root->left,p,q);
        Node* right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL) return root;
        else if(left!=NULL && right==NULL) return left;
        else if(left==NULL && right!=NULL) return right;
        else return NULL;
    }
    int solve(Node* root,int k,int dist){
        if(root==NULL) return -1;
        if(root->data==k) return dist;
        int left=solve(root->left,k,dist+1);
        if(left!=-1) return left;
        return solve(root->right,k,dist+1);
    }
    int findDist(Node* root, int a, int b) {
        Node* lca=lowestCommonAncestor(root,a,b);
        int distA=solve(lca,a,0);// 0 here is the current distance trvelled
        int distB=solve(lca,b,0);
        return distA+distB;
    }