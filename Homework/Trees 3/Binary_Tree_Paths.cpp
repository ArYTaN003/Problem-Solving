vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        if(root->left==NULL && root->right==NULL) return {to_string(root->val)};
        vector<string> out;
        vector<string> l=binaryTreePaths(root->left);
        vector<string> r=binaryTreePaths(root->right);
        string s = to_string(root->val);
        for(int i=0;i<l.size();i++){
            out.push_back(s+"->"+l[i]);
        }
        for(int i=0;i<r.size();i++){
            out.push_back(s+"->"+r[i]);
        }
        return out;
    }