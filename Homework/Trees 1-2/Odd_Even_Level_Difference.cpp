int getLevelDiff(Node *root)
    {
       
       if(root==NULL) return 0;
       int odd_level_sum = 0;
       int even_level_sum = 0;
       int diff = 0;
       queue<pair<Node*,int>> q;
       q.push({root,1});
       Node* f;
       int l;
       while(!q.empty()){
           f = q.front().first;
           l = q.front().second;
           q.pop();
           if(l&1) odd_level_sum+=f->data;
           else even_level_sum+=f->data;
           if(f->left) q.push({f->left,l+1});
           if(f->right) q.push({f->right,l+1});
       }
       return odd_level_sum-even_level_sum;
    }