vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> out;
        if(root==NULL){
            return out;
        }
        if(!root->left && !root->right && root->val==targetSum){
            out.push_back({root->val});
            return out;
        }
        out = pathSum(root->left,targetSum-root->val);
        vector<vector<int>> r = pathSum(root->right,targetSum-root->val);
        for(int i=0;i<r.size();i++){
            out.push_back(r[i]);
        }
        for(int i=0;i<out.size();i++){
            out[i].insert(out[i].begin(),root->val);
        }
        return out;
    }