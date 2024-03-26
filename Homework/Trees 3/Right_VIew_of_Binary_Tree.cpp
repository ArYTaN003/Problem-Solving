vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ary;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        TreeNode* front;
        int l;
        while(!q.empty()){
            front=q.front().first;
            l = q.front().second;
            q.pop();
            if(l==ary.size()) ary.push_back(front->val);
            else if(l<ary.size()) ary[l] = front->val;
            if(front->left) q.push({front->left,l+1});
            if(front->right) q.push({front->right,l+1});
            
        }
        return ary;
    }