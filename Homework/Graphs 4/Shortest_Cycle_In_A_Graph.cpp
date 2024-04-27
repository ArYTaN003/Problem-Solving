class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n,-1);
        int ary = -1;
        for(int i=0;i<n;i++){
            fill(visited.begin(),visited.end(),-1);
            queue<pair<int,int>> q;
            q.push({i,i});
            visited[i] = 1;
            while(!q.empty()){
                int f = q.front().first;
                int p = q.front().second;
                q.pop();
                for(int v:adj[f]){
                    if(v==p) continue;
                    if(visited[v]==-1){
                        visited[v] = visited[f]+1;
                        q.push({v,f});
                    }
                    else{
                        if(ary==-1) ary = visited[f]+visited[v]-1;
                        else ary = min(ary,visited[f]+visited[v]-1);
                    }
                }
            }
        }
        return ary;
    }
};