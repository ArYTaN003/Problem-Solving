vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> ary;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push({root,0});
    BinaryTreeNode<int> * f;
    int l;
    while(!q.empty()){
        f = q.front().first;
        l = q.front().second;
        q.pop();
        if(l==ary.size()) ary.push_back(f->data);
        if(f->left) q.push({f->left,l+1});
        if(f->right) q.push({f->right,l+1});
    }
    return ary;
}