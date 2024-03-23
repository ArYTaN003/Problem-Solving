vector<int> topView(Node *root)
    {
        vector<int> out; 
        map<int,int> vertical_level;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        Node* f;
        int v;
        while(!q.empty()){
            f = q.front().first;
            v = q.front().second;
            q.pop();
            if(vertical_level.count(v)==0) vertical_level[v] = f->data;
            if(f->left) q.push({f->left,v-1});
            if(f->right) q.push({f->right,v+1});
        }
        for(auto it:vertical_level){
            out.push_back(it.second);
        }
        return out;
    }