vector <int> bottomView(Node *root) {
        vector<int> out;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        Node*f;
        int v;
        while(!q.empty()){
            f = q.front().first;
            v = q.front().second;
            q.pop();
            mp[v] = f->data;
            if(f->left) q.push({f->left,v-1});
            if(f->right) q.push({f->right,v+1});
        }
        for(auto it:mp){
            out.push_back(it.second);
        }
        return out;
    }