// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        queue<TreeNode*> q;
        q.push(root);
        string ans="";
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur==NULL) ans+="#,";
            else ans+=(to_string(cur->val)+',');
            if(cur!=NULL){
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                cur->left=NULL;
            }
            else{
                TreeNode* l=new TreeNode(stoi(str));
                cur->left=l;
                q.push(l);
            }
            getline(s,str,',');
            if(str=="#"){
                cur->right=NULL;
            }
            else{
                TreeNode* r=new TreeNode(stoi(str));
                cur->right=r;
                q.push(r);
            }
        }
        return root;
    }