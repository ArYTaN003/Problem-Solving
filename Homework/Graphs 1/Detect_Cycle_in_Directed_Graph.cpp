class Solution {
    bool dfs(vector<int> adj[],int src,vector<bool>& visited,vector<bool>& visited2){
        visited[src] = true;
        visited2[src] = true;
        for(int i:adj[src]){
            if((!visited[i] && dfs(adj,i,visited,visited2)) || visited2[i]){
                visited2[src] = false;
                return true;
            }
        }
        visited2[src] = false;
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        // We use 2 visited arrays , one to check whether we have visited the node or not
        // Other to check whether in the current recursion , we have visited the node or not
        vector<bool> visited(V,false);
        vector<bool> visited2(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(adj,i,visited,visited2)) return true;   
        }
        return false;
    }
};