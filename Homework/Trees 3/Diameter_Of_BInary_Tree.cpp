 int diameter(TreeNode* root,int & m){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int l = diameter(root->left,m);
        int r = diameter(root->right,m);
        m = max(m,l+r+1);
        m = max(m,1+max(l,r));
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       int maxi = 0;
       diameter(root,maxi);
       return maxi>0?maxi-1:0;
    }