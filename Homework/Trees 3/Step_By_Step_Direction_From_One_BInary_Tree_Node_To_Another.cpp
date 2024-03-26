TreeNode* lca(TreeNode* root,int& s,int& d){
        if(root==NULL || root->val==s || root->val==d) return root;
        TreeNode*left = lca(root->left,s,d);
        TreeNode*right = lca(root->right,s,d);
        if(left!=NULL && right!=NULL){
            return root;
        }else if(left!=NULL) return left;
        else return right;
    }
    bool getPath(TreeNode* root,int& v,string& path){
        if(root==NULL) return false;
        if(root->val==v) return true;
        if(getPath(root->left,v,path)){
            path+="L";
            return true;
        }else if(getPath(root->right,v,path)){
            path+="R";
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s_path = "",d_path="";        
        // Find LCA , as Shortest Path will be through the LCA
        TreeNode* anc = lca(root,startValue,destValue);
        // Get Path from LCA to start
        getPath(anc,startValue,s_path);
        for(int i=0;i<s_path.length();i++){
            s_path[i] = 'U';
        }
        // Get Path from LCA to end
        getPath(anc,destValue,d_path);
        // We need to reverse the path as the path we get is from destValue to LCA
        reverse(d_path.begin(),d_path.end());
        return s_path+d_path;
    }