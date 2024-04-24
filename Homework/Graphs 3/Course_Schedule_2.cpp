class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n,vector<int>());
        for(auto i:prereq){
            indegree[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        vector<int> ary;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        int f;
        while(!q.empty()){
            f = q.front();
            q.pop();
            ary.push_back(f);
            for(int v:adj[f]){
                if(indegree[v]>0){
                    indegree[v]--;
                    if(indegree[v]==0) q.push(v);
                }
            }
        }
        if(ary.size()==n) return ary;
        return {};
    }
};