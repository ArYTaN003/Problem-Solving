vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ary;
        unordered_map<int,vector<pair<int,int>>> mp;
        int min_level = 0,i,v,h;
        TreeNode * f;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            f = q.front().first;
            v = q.front().second.first;
            h = q.front().second.second;
            q.pop();
            mp[v].push_back({f->val,h});
            min_level = min(v,min_level);
            if (f->left) q.push({f->left,{v-1,h+1}});
            if (f->right) q.push({f->right,{v+1,h+1}});
        }
        while(mp.count(min_level)>0){
            sort(mp[min_level].begin(),mp[min_level].end(),[&](pair<int,int>&a,pair<int,int>&b){
                return a.second==b.second?a.first<b.first:a.second<b.second;
            });
            ary.push_back({});
            i = ary.size()-1;
            for(auto it:mp[min_level]){
                ary[i].push_back(it.first);
            }
            min_level++;
        }
        return ary;
    }