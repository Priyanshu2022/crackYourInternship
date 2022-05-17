// store in queue
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* it=q.front();
                q.pop();
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
                temp.push_back(it->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }



vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool f=1;
        while(!q.empty()){
            int size=q.size();
            vector<int> temp(size);
            for(int i=0;i<size;i++){
                int index=(f)?i:(size-i-1);
                TreeNode* cur=q.front();
                q.pop();
                temp[index]=cur->val;
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            ans.push_back(temp);
            f=!f;
        }
        return ans;
    }



// print left node's (except last ) , print leaf nodes , then right nodes (except last)
void traverseLeft(Node* root, vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)) return;
        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left,ans);
        }
        else traverseLeft(root->right,ans);
    }
    void traverseRight(Node* root,vector<int> &ans){
        if(root==NULL || (root->left==NULL && root->right==NULL)) return ;
        if(root->right){
            traverseRight(root->right,ans);
        }
        else traverseRight(root->left,ans);
        ans.push_back(root->data);
    }
    void traverseLeaf(Node* root,vector<int> &ans){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL) ans.push_back(root->data);
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        traverseLeft(root->left,ans);
        
        // if pass with the root and only one root present , then ans will have two roots
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);

        traverseRight(root->right,ans);
        
        return ans;
    }



// map of <hd , map<level,values>>
// queue of node and hd,level
vector<int> verticalOrder(Node *root)
    {
        // hd       level  node's value 
        map<int,map<int,vector<int>>> mp;
        vector<int> ans;
        if(root==NULL) return ans;
        
        //        node        hd  level
        queue<pair<Node*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int hd=temp.second.first;
            int lvl=temp.second.second;
            mp[hd][lvl].push_back(temp.first->data);
            if(temp.first->left) q.push({temp.first->left,{hd-1,lvl+1}});
            if(temp.first->right) q.push({temp.first->right,{hd+1,lvl+1}});
        }
        for(auto i:mp){
            for(auto j:i.second){
                for(auto cur:j.second){
                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }


// make map of int ,int and update only when new hd comes
vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        //  hd  root'data
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop();  
            Node* node = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end())
            mpp[line] = node->data; 
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;
    }

// update everytime you see a new hd
vector <int> bottomView(Node *root) {
         vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop();  
            Node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; 
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;
    }

// left view , maintain level and compare with vector of ans .size
void solve(Node * root,vector<int> &ans,int level){
    if(root==NULL ) return;
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root,ans,0);
   return ans;
}

// right view, go to the right first
void solve(Node * root,vector<int> &ans,int level){
        if(!root) return;
        if(ans.size()==level){
            ans.push_back(root->data);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);

    }
    
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       solve(root,ans,0);
       return ans;
    }


// diagonal traversal
// push root in queue
// in while loop
// move to right of front node
// push if left exist 
// put in ans then move right
vector<int> diagonal(Node *root)
{
   vector<int> ans;
   if(root==NULL) return ans;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       Node* temp=q.front();
       q.pop();
       while(temp){
           if(temp->left) q.push(temp->left);
           ans.push_back(temp->data);
           temp=temp->right;
       }
   }
   return ans;
}