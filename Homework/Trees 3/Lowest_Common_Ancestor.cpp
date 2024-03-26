TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root->val==p->val || root->val==q->val) return root;
        TreeNode * l = lowestCommonAncestor(root->left,p,q);
        TreeNode * r = lowestCommonAncestor(root->right,p,q);
        if(l!=NULL && r!=NULL){
            return root;
        }else if(l!=NULL) return l;
        else return r;
    }