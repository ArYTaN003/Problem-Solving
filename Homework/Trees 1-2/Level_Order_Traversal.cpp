vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        if(root==NULL){
            return out;
        }
        out.push_back({});
        queue<TreeNode*> q;
        int curr_level = 0;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode *front=q.front();
            q.pop();
            if(front==NULL){
                if(!q.empty()){
                    // More levels are present
                    out.push_back({});
                    curr_level++;
                    q.push(NULL);
                }
                continue;
            }
            out[curr_level].push_back(front->val);
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
        return out;
    }