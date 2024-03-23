int heightOfBinaryTree(TreeNode<int> *root)
{
    if(root==NULL) return 0;
    int height = 1;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,1});
    TreeNode<int> *f;
    int l;
    while(!q.empty()){
        f = q.front().first;
        l = q.front().second;
        q.pop();
        height = max(height,l);
        if(f->left) q.push({f->left,l+1});
        if(f->right) q.push({f->right,l+1});
    }
    return height;

}