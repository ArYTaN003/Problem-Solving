int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        bool pechla_null = true;
        q.push(root);
        q.push(NULL);
        int ans = -1;
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            if(f==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                pechla_null = true;
                continue;
            }
            // Since last value was null, it means this is the first value of the current level
            if(pechla_null) ans = f->val;
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
            pechla_null = false; 
        }
        return ans;
    }