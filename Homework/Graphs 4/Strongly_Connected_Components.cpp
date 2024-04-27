class Solution
{
    void dfs1(vector<vector<int>>& adj,int curr,stack<int>& dfs_seq,vector<bool>& visited){
        visited[curr] = true;
        for(int v:adj[curr]){
            if(!visited[v]){
                dfs1(adj,v,dfs_seq,visited);
            }
        }
        dfs_seq.push(curr);
    }
    void dfs2(vector<vector<int>>& adj,int curr,vector<bool>& visited){
        visited[curr] = true;
        for(int v:adj[curr]){
            if(!visited[v]){
                dfs2(adj,v,visited);
            }
        }
    }
	public:
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        stack<int> dfs_seq;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs1(adj,i,dfs_seq,visited);
            }
        }
        vector<vector<int>> rev_adj(V);
        for(int i=0;i<V;i++){
            for(int u:adj[i]){
                rev_adj[u].push_back(i);
            }
        }
        fill(visited.begin(),visited.end(),false);
        int ary = 0;
        while(!dfs_seq.empty()){
            int u = dfs_seq.top();
            dfs_seq.pop();
            if(!visited[u]){
                dfs2(rev_adj,u,visited);
                ary++;
            }
        }
        return ary;
    }
};