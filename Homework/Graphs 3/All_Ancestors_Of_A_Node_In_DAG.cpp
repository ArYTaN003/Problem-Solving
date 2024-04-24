class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> mp(n,set<int>());
        vector<vector<int>> adj(n,vector<int>());
        vector<int> indegree(n,0);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        int f;
        while(!q.empty()){
            f = q.front();
            q.pop();
            for(int u:adj[f]){
                if(indegree[u]>0){
                    mp[u].insert(f);
                    for(int i:mp[f]){
                        mp[u].insert(i);
                    }
                    indegree[u]--;
                    if(indegree[u]==0) q.push(u);
                }
            }
        }
        vector<vector<int>> ary(n,vector<int>());
        for(int i=0;i<n;i++){
            for(int u:mp[i]){
                ary[i].push_back(u);
            }
            sort(ary[i].begin(),ary[i].end());
        }
        return ary;
    }
};