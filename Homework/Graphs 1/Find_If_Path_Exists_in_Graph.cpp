class Solution {
    bool dfs(unordered_map<int,vector<int>>& adj,int x,int y,vector<bool>& visited){
        if(x==y) return true;
        visited[x] = true;
        for(int i:adj[x]){
            if(!visited[i] && dfs(adj,i,y,visited)){
                return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adj;
        int m = edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        return dfs(adj,source,destination,visited);
    }
};