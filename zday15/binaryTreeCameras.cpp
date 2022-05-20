// hidden cameras
// we have to place minimum cameras in nodes so that every node is covered 
// (a camera looks over parent and it's children)
// we will check from bottom (post order)
// process after calculating left and right
// first check if any of the children want then camera , if yes then increase and return provide
// other wise if any of them provide , then return 'ok' , that means this is covered
// if both the child nodes are 'ok' return 'want'

// at last check if the root itself , want a camera then increase 
string solve(TreeNode* root,int &numberOfCameras){
        if(root==NULL) return "ok";
        string left=solve(root->left,numberOfCameras);
        string right=solve(root->right,numberOfCameras);
        if(left=="want" || right=="want"){
            numberOfCameras++;
            return "provide";
        }
        else if(left=="provide" || right=="provide"){
            return "ok";
        }
        else return "want";
    }
    int minCameraCover(TreeNode* root) {
        int numberOfCameras=0;
        if(solve(root,numberOfCameras)=="want") numberOfCameras++;
        return numberOfCameras;
    }